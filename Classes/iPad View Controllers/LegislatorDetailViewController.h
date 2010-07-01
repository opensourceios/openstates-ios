//
//  LegislatorDetailViewController.h
//  TexLege
//
//  Created by Gregory Combs on 6/28/10.
//  Copyright 2010 Gregory S. Combs. All rights reserved.
//

#import <UIKit/UIKit.h>

@class LegislatorObj;
@class StaticGradientSliderView;
@interface LegislatorDetailViewController : UITableViewController <UIPopoverControllerDelegate, UISplitViewControllerDelegate>
{	
    UIPopoverController *popoverController;
	//IBOutlet UIBarButtonItem *m_popButton;

	IBOutlet StaticGradientSliderView *indivSlider, *partySlider, *allSlider;
	IBOutlet UIView *indivPHolder, *partyPHolder, *allPHolder;
	IBOutlet UIView *indivView, *partyView, *allView;
	
	LegislatorObj *legislator;
	
	IBOutlet UIImageView *leg_photoView;
	IBOutlet UILabel *leg_partyLab, *leg_districtLab, *leg_tenureLab, *leg_nameLab;
}

@property (nonatomic,retain) IBOutlet UIImageView *leg_photoView;
@property (nonatomic,retain) IBOutlet UILabel *leg_titleLab, *leg_partyLab, *leg_districtLab, *leg_tenureLab, *leg_nameLab;
@property (nonatomic,retain) IBOutlet StaticGradientSliderView *indivSlider, *partySlider, *allSlider;
@property (nonatomic,retain) IBOutlet UIView *indivPHolder, *partyPHolder, *allPHolder;
@property (nonatomic,retain) IBOutlet UIView *indivView, *partyView, *allView;

@property (nonatomic,retain) LegislatorObj *legislator;
@property (nonatomic, retain) UIPopoverController *popoverController;
//@property (nonatomic, retain) IBOutlet UIBarButtonItem *m_popButton;

//- (IBAction)showMasterInPopover:(id)sender;
@end
