import UIKit

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate {
    
    var window: UIWindow?
    
    func application(_ application: UIApplication, _didFinishLaunchingWithOptions launchOptions: NSDictionary?) -> Bool {
        self.localNotificationPermission()
        return true
    }
    
    func localNotificationPermission() -> Void {
        let types : UIUserNotificationType = [UIUserNotificationType.badge, UIUserNotificationType.alert, UIUserNotificationType.sound]
        let settings : UIUserNotificationSettings = UIUserNotificationSettings(types: types, categories:nil)
        let app = UIApplication.shared
        app.registerUserNotificationSettings(settings)
    }
}

