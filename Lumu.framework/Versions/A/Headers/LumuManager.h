//
//  LumuManager.h
//  Lumu
//
//  Created by Benjamin Polovič on 27. 04. 13.
//
//


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/*
 * LumuManagerDelegate
 */

@protocol LumuManagerDelegate <NSObject>
@optional

/*!
 * Called if the application does not have the microphone permission.
 */
-(void)lumuManagerDidNotGetRecordPermission;

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
 * @param value the received light value (lux)
 */
-(void)lumuManagerDidReceiveData: (CGFloat)value;

/*!
 * This method is called every time the manager starts communicating with Lumu.
 */
-(void)lumuManagerDidStartLumu;

/*!
 * This method is called every time the manager stops communicating with Lumu.
 */
-(void)lumuManagerDidStopLumu;

@end

@interface LumuManager : NSObject

/*
 * The delegate property. The delegate has to be set for
 * LumuManager to start working.
 * When the delegate is set to nil, LumuManager stops working.
 */

@property (nonatomic, weak) id <LumuManagerDelegate> delegate;

/*
 * This property defines if the audio communication is active.
 */

@property (nonatomic, readonly) BOOL audioCommunicationActive;

/*
 * This property defines if the Lumu was recognized and is communicating 
 * with the device.
 */

@property (nonatomic, readonly) BOOL lumuCommunicationActive;

/*
 * Shared instance.
*/

+ (LumuManager *)sharedManager;

/*
 * Tries to start Lumu. If Lumu is already running, or there is a problem with Audio session,
 * or the device is not attched this method returns NO. If successful it returns YES.
 */

- (BOOL)startLumuManager;

/*
 * Stop Lumu manager.
 */

- (void)stopLumuManager;

/*
 * Convert Lux value to Foot Candles.
 */

- (CGFloat)convertToFootCandles: (CGFloat)lux;


@end