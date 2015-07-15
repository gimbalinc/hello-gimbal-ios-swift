# Gimbal iOS Swift Basic Sample
Minimal Gimbal Integration Example on iOS written in Swift. After setting up your application, place(s) and communication(s) using the Gimbal Manager the code below will yield **Place Events** and **Local Notifications**.

## Before you create your iOS application
Using the **Gimbal Manager**:
[https://manager.gimbal.com/](https://manager.gimbal.com/)
- create your Gimbal account 
- create an **Application** using bundle ID **com.gimbal.hello-gimbal-swift** (generates you API KEY)
- create at least one **Place** (using a Beacon or Geofence) you can buy Beacons here [http://store.gimbal.com/](http://store.gimbal.com/)
- create at least one **Communicate** (used for the local notification)
- download the latest V2 SDK

## In the sample iOS application
- fill your API KEY into ViewController.swift
- add the Gimbal.framework from the SDK zip you downloaded
- to enable Gimbal to operate in the background set your application to **'Uses Bluetooth LE accessories'** background mode 

Full Gimbal Docs [https://gimbal.com/docs](https://gimbal.com/docs)
