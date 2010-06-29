//
//  DetailTableViewController.h
//  TexLege
//
//  Created by Gregory S. Combs on 5/31/09.
//  Copyright 2009 Gregory S. Combs. All rights reserved.
//

 
#import "Constants.h"

#import "DirectoryDetailView.h"
#include "VoteInfoViewController.h"

//#import "MapImageView.h"

@class LegislatorObj;
@class CommitteeObj;


@interface DetailTableViewController : UITableViewController <UITableViewDelegate>{

	UIView *containerView;	
	
	NSURL *webViewURL;
	NSString *mapFileName;
//	MapImageView *mapImageView;
	UIWebView *webPDFView;

	LegislatorObj *legislator;

	DirectoryDetailView *legislatorView;
}

@property (nonatomic,retain) UIView *containerView;

//@property (nonatomic,retain) MapImageView *mapImageView;
@property (nonatomic,retain) NSString *mapFileName;
@property (nonatomic,retain) UIWebView *webPDFView;
@property (nonatomic,retain) NSURL *webViewURL;

@property (nonatomic,retain) LegislatorObj *legislator;
@property (nonatomic,retain) DirectoryDetailView *legislatorView;

- (void) showWebViewWithURL:(NSURL *)url;
- (void) pushMapViewWithURL:(NSURL *)url;
- (void) pushInternalBrowserWithURL:(NSURL *)url;
	
@end
