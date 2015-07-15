import UIKit

class ViewController: UITableViewController, GMBLPlaceManagerDelegate {
    var placeManager: GMBLPlaceManager!
    var placeEvents: NSMutableArray = []
    
    override func viewDidLoad() -> Void {
        var options: NSDictionary = ["GIMBAL_SERVER_BASE_URL" : "https://ios.api.stage.gimbal.com/service/",
            "PROXIMITY_SERVER_BASE_URL" : "https://proximity.stage.gimbal.com/",
            "BEACON_RESOLVE_SERVER_BASE_URL" : "https://resolve-stage.gimbal.com/",
            "PLACE_BUBBLE_SERVER_BASE_URL" : "https://placebubble-stage.gimbal.com/service/"]
        Gimbal.setAPIKey("e86d243d-2fa2-4a4a-8599-2f3da33bd531", options: options as [NSObject : AnyObject])
        placeManager = GMBLPlaceManager()
        self.placeManager.delegate = self
        GMBLPlaceManager.startMonitoring()
        
        GMBLCommunicationManager.startReceivingCommunications()
    }
    
    func placeManager(manager: GMBLPlaceManager!, didBeginVisit visit: GMBLVisit!) -> Void {
        NSLog("Begin %@", visit.place.description)
        self.placeEvents.insertObject(visit, atIndex: 0)
        self.tableView.insertRowsAtIndexPaths([NSIndexPath(forRow: 0, inSection: 0)], withRowAnimation:UITableViewRowAnimation.Automatic)
    }
    
    func placeManager(manager: GMBLPlaceManager!, didEndVisit visit: GMBLVisit!) -> Void {
        NSLog("End %@", visit.place.description)
        self.placeEvents.insertObject(visit, atIndex: 0)
        self.tableView.insertRowsAtIndexPaths([NSIndexPath(forRow: 0, inSection: 0)], withRowAnimation: UITableViewRowAnimation.Automatic)
    }
    
    override func tableView(tableView: UITableView, numberOfRowsInSection section: NSInteger) -> NSInteger {
        return self.placeEvents.count
    }
    
    override func tableView(tableView: UITableView, cellForRowAtIndexPath indexPath: NSIndexPath) -> UITableViewCell {
        var cell: UITableViewCell = tableView.dequeueReusableCellWithIdentifier("cell", forIndexPath: indexPath) as! UITableViewCell
        var visit: GMBLVisit = self.placeEvents[indexPath.row] as! GMBLVisit
        
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

