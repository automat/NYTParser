//
//  NYTUtils.m
//  NYTParser
//
//  Created by Henryk on 29.09.12.
//  Copyright (c) 2012 Henryk. All rights reserved.
//

#import "NYTResource.h"

static NSString* const URL_XML_GEONAMES_COUNTRYCODES = @"http://ws.geonames.org/countryInfo";

@implementation NYTResource

@synthesize parsedData = _parsedData;

-(id)init
{
    if(self = [super init])
    {
        _xmlParser  = [[NSXMLParser alloc]init];
        _parsedData = [NSMutableArray array];
    }
    return self;
}

-(void)requestXMLFromURL:(NSString *)url
{
   NSURL* nurl = [NSURL URLWithString:@"http://ws.geonames.org/countryInfo?geonames&format=xml"];
   NSMutableURLRequest* r = [NSMutableURLRequest requestWithURL:nurl];
   NSData* xmlData = [ NSURLConnection sendSynchronousRequest:r returningResponse: nil error: nil ];
   NSXMLParser* p = [[NSXMLParser alloc] initWithData:xmlData];
   [p setDelegate:self];
   [p parse];
   
}

-(void)parser:(NSXMLParser *)parser didStartElement:(NSString *)elementName namespaceURI:(NSString *)namespaceURI qualifiedName:(NSString *)qName attributes:(NSDictionary *)attributeDict
{
    //NSXMLElement* e = NSXMLElement e
    
    static int c = 0;
    NSLog(@"%@",elementName);
    if([elementName isEqualToString:@"countryName"])//NSLog(@"ff%@",[attributeDict valueForKey:@"countryName"]);
    
    ++c;
}

static NYTResource* _instance = nil;

+(NSArray*)listAllCountries
{
    if (!_instance)_instance = [[NYTResource alloc] init];
    
    [_instance requestXMLFromURL:URL_XML_GEONAMES_COUNTRYCODES];
    
    return _instance.parsedData;
}


@end
