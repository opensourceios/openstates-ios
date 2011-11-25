//
//  BillSearchParameters.m
//  Created by Greg Combs on 11/6/11.
//
//  StatesLege by Sunlight Foundation, based on work at https://github.com/sunlightlabs/StatesLege
//
//  This work is licensed under the Creative Commons Attribution-NonCommercial 3.0 Unported License. 
//  To view a copy of this license, visit http://creativecommons.org/licenses/by-nc/3.0/
//  or send a letter to Creative Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
//
//

#import "BillSearchParameters.h"
#import "SLFDataModels.h"
#import <RestKit/Network/NSObject+URLEncoding.h>

NSString* validOrEmptyParameter(NSString *parameter);
NSString* validSessionParameter(NSString *session);

@implementation BillSearchParameters

+ (NSString *)pathForBill:(NSString *)billID state:(NSString *)stateID session:(NSString *)session {
	NSParameterAssert((stateID != NULL) && (billID != NULL) && (session != NULL));
	NSDictionary *queryParams = [NSDictionary dictionaryWithObjectsAndKeys:
										stateID, @"state",
										session, @"session",
										SUNLIGHT_APIKEY, @"apikey", 
                                        billID, @"bill", nil];
    return RKMakePathWithObject(@"/bills/:state/:session/:bill?:apikey", queryParams);
}

+ (NSString *)pathForBill:(SLFBill *)bill {
	NSParameterAssert((bill != NULL) && (bill.state != NULL) && (bill.billID != NULL) && (bill.session != NULL));
    return [RKMakePathWithObject(@"/bills/:stateID/:session/:billID?apikey=", bill) stringByAppendingString:SUNLIGHT_APIKEY];
}

+ (NSString *)pathForText:(NSString *)text state:(NSString *)stateID session:(NSString *)session chamber:(NSString *)chamber {
	NSParameterAssert((stateID != NULL));
    text = [validOrEmptyParameter(text) uppercaseString];
	NSMutableDictionary *queryParams = [NSMutableDictionary dictionaryWithObjectsAndKeys:
										validSessionParameter(session), @"search_window",
										stateID, @"state",
										SUNLIGHT_APIKEY, @"apikey", 
                                        text, @"q", nil];
	if (chamber && ![chamber isEqualToString:@"all"])
		[queryParams setObject:chamber forKey:@"chamber"];
    return RKPathAppendQueryParams(@"/bills", queryParams);
}

+ (NSString *)pathForText:(NSString *)text chamber:(NSString *)chamber {
    SLFState *state = SLFSelectedState();
	if (!state)
		return nil;
    NSString *session = SLFSelectedSessionForState(state);
	return [[self class] pathForText:text state:state.stateID session:session chamber:chamber];
}

+ (NSString *)pathForSubject:(NSString *)subject state:(NSString *)stateID session:(NSString *)session chamber:(NSString *)chamber {
	NSCParameterAssert((stateID != NULL));
    subject = validOrEmptyParameter(subject);
	NSMutableDictionary *queryParams = [NSMutableDictionary dictionaryWithObjectsAndKeys:
										validSessionParameter(session), @"search_window",
										stateID, @"state",
										SUNLIGHT_APIKEY, @"apikey",
                                        subject, @"subject", nil];
	if (chamber && ![chamber isEqualToString:@"all"])
		[queryParams setObject:chamber forKey:@"chamber"];
    return RKPathAppendQueryParams(@"/bills", queryParams);
}

+ (NSString *)pathForSubject:(NSString *)subject chamber:(NSString *)chamber {
    SLFState *state = SLFSelectedState();
	if (!state)
		return nil;
	NSString *session = SLFSelectedSessionForState(state);
	return [[self class] pathForSubject:subject state:state.stateID session:session chamber:chamber];
}

+ (NSString *)pathForSponsor:(NSString *)sponsorID state:(NSString *)stateID session:(NSString *)session {
	NSCParameterAssert( (sponsorID != NULL) && (stateID != NULL) );
	NSDictionary *queryParams = [NSDictionary dictionaryWithObjectsAndKeys:
								 stateID, @"state",
								 validSessionParameter(session), @"search_window",
								 SUNLIGHT_APIKEY, @"apikey",
								 sponsorID, @"sponsor_id",
								 @"sponsors,bill_id,title,session,state,type,update_at,subjects", @"fields", nil];
	return RKPathAppendQueryParams(@"/bills", queryParams);
}

+ (NSString *)pathForSponsor:(NSString *)sponsorID {
    SLFState *state = SLFSelectedState();
	if (!state || IsEmpty(sponsorID))
		return nil;
	NSString *session = SLFSelectedSessionForState(state);
    return [[self class] pathForSponsor:sponsorID state:state.stateID session:session];
}

@end

NSString* validOrEmptyParameter(NSString *parameter) {
    if (IsEmpty(parameter))
		parameter = @"";
    return parameter;
}

NSString* validSessionParameter(NSString *session) {
    if (IsEmpty(session))
        return @"session";
    return [NSString stringWithFormat:@"session:%@", [session URLEncodedString]];
}

