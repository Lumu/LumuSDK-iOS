<p align="center">
  <a href="http://lu.mu/"><img src="http://lu.mu/images/logo.png" alt="Lumu" title="Lumu" width="150px" /></a>
</p>

## Lumu iOS SDK

The Lumu SDK helps you connect [Lumu](http://lu.mu/) to your iOS application. It provides the essential methods for managing the connection with Lumu and receiving data.

Lumu is a light meter for iOS devices that helps you take great photos. For more information about Lumu please visit our [website](http://lu.mu/).

## Installation

1. Add the ``Lumu.framework`` to your project
2. Link the ``AVFoundation.framework``, ``MediaPlayer.framework``, ``AudioToolbox.framework`` and ``CoreTelephony.framework`` to your project
3. Import ``LumuManager.h`` in your class
4. Start measuring!

## Usage

To start receiving data from Lumu in your class, you have to complete the following steps:

1. Conform to the ``LumuManagerDelegate`` protocol
2. Register your class as the delegate for Lumu: ``[LumuManager sharedManager].delegate = self;``
3. Implement the optional protocol methods, to receive data from Lumu

LumuManager provides the next optional protocol methods: 
```objectivec
/*!
 * This method is called when the attached device is recognized as Lumu.
 */
-(void)lumuManagerDidRecognizeLumu;

/*!
 * This method is called when the attached device is NOT recognized as Lumu.
 */
-(void)lumuManagerDidNotRecognizeLumu;

/*!
 * This method is called every time the manager receives a new value from Lumu.
 * @param value the received light value
 */
-(void)lumuManagerDidReceiveData: (double)value;

/*!
 * This method is called every time the manager starts communicating with Lumu.
 */
-(void)lumuManagerDidStartLumu;

/*!
 * This method is called every time the manager stops communicating with Lumu.
 */
-(void)lumuManagerDidStopLumu;
```

By default, the LumuManager will try to start Lumu as soon as you set the delegate property. It will also automatically stop and start Lumu when you detach/attach it. 
If you would like to manually start and stop Lumu you have to set the ``shouldRecognizeLumu`` property to ``NO``, before you set the delegate property. Then you have to use ``startLumuManager`` and ``stopLumuManager`` methods.

You can convert the light measurement from Lux to Foot-candles with the ``convertToFootCandles: (CGFloat)lux`` method.

## Example

The example project uses the Lumu SDK to receive data from Lumu and to simply display this value on a Label.
It stops the LumuManager when the App stops being active, and starts it when the App is in the foreground again.


## FAQ

### Can I use Lumu SDK without a Lumu?

No. In order to get light measurements and a response from the SDK you need Lumu. You can order one from [our website](http://lu.mu/).

## Feedback

If you have any questions, troubles or comments, please send us an email to support@lu.mu and we will help you.
