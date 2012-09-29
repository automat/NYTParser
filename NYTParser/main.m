//
//  main.m
//  NYTParser
//
//  Created by Henryk on 27.09.12.
//  Copyright (c) 2012 Henryk. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NYTArticleSearchQuery.h"
#import "NYTFacet.h"
#import "NYTResource.h"


int main(int argc, const char * argv[])
{

    @autoreleasepool {
       
        NYTArticleSearchQuery* query = [NYTArticleSearchQuery query];
        //[query search:FIELD_TEXT keywords:@"germany",@"angela merkel",@"obama", nil];
        //[query excludeKeywords:@"New York", nil];
        
        //Test 1
        /*
        [query search:FIELD_TITLE keywords:@"election", nil];
        [query search:FIELD_ABSTRACT keywords:@"turnout", nil];
        [query addReturnFields:RETURN_TITLE,RETURN_LEAD_PARAGRAPH,RETURN_URL,RETURN_DATE, nil];
        [query setDateBegin:@"20081001"];
        [query setDateEnd:@"20081201"];
         */
        
        [NYTResource listAllCountries];
        
        
        [query addFacetes:[NYTFacet facetWithType:FACET_GEO query:@"United States"], nil];
        [query addReturnFields:RETURN_DES, nil];
        
        
        
        NSString* requestURL = [query requestURL];
        NSLog(@"%@",requestURL);
        
        NSMutableURLRequest*   request    = [NSURLRequest requestWithURL:[NSURL URLWithString:requestURL]];
        NSData*                jsonData   = [NSURLConnection sendSynchronousRequest:request returningResponse: nil error: nil];
        NSDictionary*          jsonDict   = [NSJSONSerialization JSONObjectWithData:jsonData options:kNilOptions error:nil];
        
        NSLog(@"%@",jsonDict);
       
        
        
        //[query search:FIELD_BODY   keywords:@"Alabama",@"Jo Mama", @"Abrakatabra", nil];
        //[query search:FIELD_BYLINE keywords:@"You",@"Me", @"Us together", nil];
       
        /*
        [query searchKeywords:@"economic",@"bailout",@"economic crisis",nil];
        
        [query setExcludes:@"housing",@"mortage",nil];
        [query setFacetes:[NYTFacet facetWithType:FACET_GEO query:@"Albania"],
                          [NYTFacet facetWithType:FACET_DES query:@"Layoffs and job reduction" ],nil];
        [query setReturnFacets:[NYTFacet facetWithType:RETURN_CLASSIFIERS],
                               [NYTFacet facetWithType:RETURN_DES],nil];
        
        */
        //NSLog(@"%d", [m isKindOfClass:[NYTFacet class]]);
        
        //NSLog(@"%@",[facet string]);
        
        
        
    }
    return 0;
}


