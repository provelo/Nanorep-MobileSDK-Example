//
//  ViewController.m
//  MobileSDKs-Example
//
//  Created by Pablo Rovelo on 3/20/18.
//  Copyright © 2018 Pablo Rovelo. All rights reserved.
//

#import "ViewController.h"
#import <NanorepUI/NanorepUI.h>

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)callSearchSDK:(id)sender {
    AccountParams *account = [AccountParams new];
    //    account.account = @"rbs";
    //    account.knowledgeBase = @"KnowledgeBaseMobile";
    account.account = @"gojek";
    account.knowledgeBase = @"English";
    account.nanorepContext = @{@"DeviceType": @"iOS"};
    [[NanoRep shared] prepareWithAccountParams:account];
    [[NanoRep shared] setFetchConfiguration:^(NRConfiguration *configuration, NSError *error) {
        dispatch_async(dispatch_get_main_queue(), ^{
            NRWidgetViewController *controller = [NRWidgetViewController new];
            [self presentViewController:controller animated:YES completion:nil];
        });
    }];
}
- (IBAction)callConversationSDK:(id)sender {
    AccountParams *accountParams = [AccountParams new];
    accountParams.account = @"workshop";
    accountParams.knowledgeBase = @"Pablo";
    accountParams.apiKey = @"8f8fd915-9ecf-4435-8b9e-0bda944aeca9";
    NRBotConfiguration *botConfig = [NRBotConfiguration new];
    botConfig.chatContentURL = [NSURL URLWithString:@"https://cdn-customers.nanorep.com/MobileSDK/view-rbs.html"];
    //        botConfig.chatContentURL = URL.init(string: "http://localhost/ConversationalWebView/view-rbs.html")
    botConfig.withNavBar = NO;
    [accountParams performSelector:@selector(setServer:) withObject:@"eu1-bot1"];
    NRConversationalViewController *controller = [[NRConversationalViewController alloc] initWithAccountParams:accountParams];
    controller.configuration = botConfig;
    [self.navigationController pushViewController:controller animated:YES];
}

@end
