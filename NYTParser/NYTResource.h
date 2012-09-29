//
//  NYTUtils.h
//  NYTParser
//
//  Created by Henryk on 29.09.12.
//  Copyright (c) 2012 Henryk. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NYTResource : NSObject <NSXMLParserDelegate>
{
    @private
    
    NSXMLParser*     _xmlParser;
    NSMutableArray*  _parsedData;
}

@property (nonatomic,readonly) NSMutableArray* parsedData;

+(NSArray*)listAllCountries;

@end
