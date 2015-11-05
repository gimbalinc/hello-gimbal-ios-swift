import UIKit

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate {
    
    var window: UIWindow?
    
    func application(application: UIApplication, _didFinishLaunchingWithOptions launchOptions: NSDictionary?) -> Bool {
        self.localNotificationPermission()
        return true
    }
    
    func localNotificationPermission() -> Void {
        let types : UIUserNotificationType = [UIUserNotificationType.Badge, UIUserNotificationType.Alert, UIUserNotificationType.Sound]
        let settings : UIUserNotificationSettings = UIUserNotificationSettings(forTypes: types, categories:nil)
        let app = UIApplication.sharedApplication()
        app.registerUserNotificationSettings(settings)
    }
}

