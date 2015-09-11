# Gimbal iOS Swift Basic Sample
Minimal Gimbal Integration Example on iOS written in Swift. After setting up your application, place(s) and communication(s) using the Gimbal Manager the code below will yield **Place Events** and **Local Notifications**.

## Before you create your iOS application
Using the **Gimbal Manager**:
[https://manager.gimbal.com/](https://manager.gimbal.com/)
- create your Gimbal account 
- create an **Application** using bundle ID **com.gimbal.hello-gimbal-ios** (generates you API KEY)
- create at least one **Place** (using a Beacon or Geofence) you can buy Beacons here [http://store.gimbal.com/](http://store.gimbal.com/)
- create at least one **Communicate** (used for the local notification)
- download the latest V2 SDK

## In the sample iOS application
- fill your API KEY into ViewController.swift
- add the Gimbal.framework from the SDK zip you downloaded
- to enable Gimbal to operate in the background set your application to **'Uses Bluetooth LE accessories'** background mode 

Full Gimbal Docs [http://docs.gimbal.com/](http://docs.gimbal.com/)

```swift
import UIKit

class ViewController: UITableViewController, GMBLPlaceManagerDelegate {
    
    var placeManager: GMBLPlaceManager!
    var placeEvents : [GMBLVisit] = []
    
    override func viewDidLoad() -> Void {
        Gimbal.setAPIKey("PUT_YOUR_GIMBAL_API_KEY_HERE", options: nil)
        
        placeManager = GMBLPlaceManager()
        self.placeManager.delegate = self
        GMBLPlaceManager.startMonitoring()
        
        GMBLCommunicationManager.startReceivingCommunications()
    }
    
    func placeManager(manager: GMBLPlaceManager!, didBeginVisit visit: GMBLVisit!) -> Void {
        NSLog("Begin %@", visit.place.description)
        self.placeEvents.insert(visit, atIndex: 0)
        self.tableView.insertRowsAtIndexPaths([NSIndexPath(forRow: 0, inSection: 0)], withRowAnimation:UITableViewRowAnimation.Automatic)
    }
    
    func placeManager(manager: GMBLPlaceManager!, didEndVisit visit: GMBLVisit!) -> Void {
        NSLog("End %@", visit.place.description)
        self.placeEvents.insert(visit, atIndex: 0)
        self.tableView.insertRowsAtIndexPaths([NSIndexPath(forRow: 0, inSection: 0)], withRowAnimation: UITableViewRowAnimation.Automatic)
    }
    
    override func tableView(tableView: UITableView, numberOfRowsInSection section: NSInteger) -> NSInteger {
        return self.placeEvents.count
    }
    
    override func tableView(tableView: UITableView, cellForRowAtIndexPath indexPath: NSIndexPath) -> UITableViewCell {
        var cell: UITableViewCell = tableView.dequeueReusableCellWithIdentifier("cell", forIndexPath: indexPath) as! UITableViewCell
        var visit: GMBLVisit = self.placeEvents[indexPath.row]
        
        if (visit.departureDate == nil) {
            cell.textLabel!.text = NSString(format: "Begin: %@", visit.place.name) as String
            cell.detailTextLabel!.text = NSDateFormatter.localizedStringFromDate(visit.arrivalDate, dateStyle: NSDateFormatterStyle.ShortStyle, timeStyle: NSDateFormatterStyle.MediumStyle)
        }
        else {
            cell.textLabel!.text = NSString(format: "End: %@", visit.place.name) as String
            cell.detailTextLabel!.text = NSDateFormatter.localizedStringFromDate(visit.arrivalDate, dateStyle: NSDateFormatterStyle.ShortStyle, timeStyle: NSDateFormatterStyle.MediumStyle)
        }
        
        return cell
    }
}
