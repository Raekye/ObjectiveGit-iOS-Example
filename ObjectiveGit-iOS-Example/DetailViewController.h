//
//  DetailViewController.h
//  ObjectiveGit-iOS-Example
//
//  Created by Adrian on 11/11/2013.
//  Copyright (c) 2013 You. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface DetailViewController : UIViewController <UISplitViewControllerDelegate>

@property (strong, nonatomic) id detailItem;

@property (weak, nonatomic) IBOutlet UILabel *detailDescriptionLabel;
@end
