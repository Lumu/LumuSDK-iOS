//
//  BPLViewController.m
//  LumuExample
//
//  Created by Benjamin Polovič on 10. 03. 14.
//  Copyright (c) 2014 Lumu Labs. All rights reserved.
//

#import "BPLViewController.h"

@interface BPLViewController ()
@property (weak, nonatomic) IBOutlet UILabel *label;

@end

@implementation BPLViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
	[[UIApplication sharedApplication] setStatusBarHidden:YES];
	
	[LumuManager sharedManager].delegate = self;
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)lumuManagerDidReceiveData:(CGFloat)value
{
	self.label.text = [NSString stringWithFormat:@"%.1f", value];
}

- (void)lumuManagerDidStopLumu
{
	self.label.text = @"";
}

- (NSUInteger)supportedInterfaceOrientations
{
    return UIInterfaceOrientationMaskPortrait | UIInterfaceOrientationMaskPortraitUpsideDown;
}

@end
