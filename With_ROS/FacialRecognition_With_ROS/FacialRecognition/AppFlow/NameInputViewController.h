//
//  NameInputViewController.h
//  Facial Recognition
//
//  Created by Kilian Michiels on 6/04/17.
//  Copyright © 2017 Kilian Michiels. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ViewController.h"

@interface NameInputViewController : UIViewController
@property (strong, nonatomic) IBOutlet UILabel *titleLabel;
@property (strong, nonatomic) IBOutlet UIButton *yesButton;
@property (strong, nonatomic) IBOutlet UIButton *noButton;
@property (strong, nonatomic) IBOutlet UIButton *cancelButton;

// Global statistic parameters
@property int fail;
@property int success;
@property NSObject *facialRecognitionMessage;
@property BOOL sessionSet;
@property NSDate* session;
@property NSString * user_tag;


// ROS Variables:
@property MainROSDoubleControl * ROSController;

@end
