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
 * @param value the received light value
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

-(void)lumuManagerDidRecognizeVolumeButtonPressed;
@end

@interface LumuManager : NSObject

/*
 * The delegate property. When the delegate is set, the Lumu starts running and sending data.
 * When the delegate is set to nil, Lumu stops working.
 */

@property (nonatomic, weak) id <LumuManagerDelegate> delegate;

/*
 * This property defines if the LumuManager tries to automatically recognize Lumu 
 * when Lumu is attached, and stops it on Audio interrupts. If set to NO, you have to manually
 * start LumuManager.
 * The default value is YES.
 */

@property BOOL shouldRecognizeLumu;

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