//
//  NRFAQGroup.h
//  NanorepUI
//
//  Created by Nissim Pardo on 03/11/2016.
//  Copyright © 2016 nanorep. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FAQAnswer.h"

@interface NRFAQGroup : NRBaseResponse
@property (nonatomic, copy, readonly) NSString *title;
@property (nonatomic, copy, readonly) NSNumber *behavior;
@property (nonatomic, copy) NSArray<NRQueryResult *> *data;
@end
