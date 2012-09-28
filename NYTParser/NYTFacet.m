//
//  NYTFacet.m
//  NYTParser
//
//  Created by Henryk on 27.09.12.
//  Copyright (c) 2012 Henryk. All rights reserved.
//

#import "NYTFacet.h"

static NSString* const RAISE_INVALID     = @"Invalid Facet";
static NSString* const RAISE_WRONG_TYPE  = @"Wrong Facet type";
static NSString* const FORMAT_INVALID    = @"Format of facet %@ is invalid";
static NSString* const FORMAT_WRONG_TYPE = @"Type of Facet is of type return. Use initWithType:query: or facetWithType:query with query %@";

static NSString* const FORMAT_STRING = @":[%@]";

@implementation NYTFacet

@synthesize name  = _name;
@synthesize query = _query;

@synthesize isReturnFacet = _isReturnFacet;

-(id)init
{
    if (self = [super init])
    {
        _name  = @"";
        _query = @"";
        _isReturnFacet = NO;
    }
    return self;
}

-(id)initWithType:(NSString *)fname query:(NSString *)fquery
{
    if (self = [super init])
    {
        [self setFacet:fname];
        [self setFacetQuery:fquery];
        _isReturnFacet = NO;
    }
    return self;
}

+(id)facetWithType:(NSString *)fname query:(NSString *)fquery
{
    return [[NYTFacet alloc]initWithType:fname query:fquery];
}

-(id)initWithType:(NSString *)fname
{
    if (self = [super init])
    {
        [self setFacet:fname];
        _query = @"";
        _isReturnFacet = YES;
    }
    
    return self;
}

+(id)facetWithType:(NSString *)fname
{
    return [[NYTFacet alloc]initWithType:fname];
}

-(void)setFacet:(NSString*)facet
{
    if ([facet isEqualToString:FACET_CLASSIFIERS] ||
        [facet isEqualToString:FACET_COLUMN] ||
        [facet isEqualToString:FACET_DATE] ||
        [facet isEqualToString:FACET_DAY_OF_WEEK] ||
        [facet isEqualToString:FACET_DBPEDIA_RESOURCE] ||
        [facet isEqualToString:FACET_DBPEDIA_RESOURCE_URL] ||
        [facet isEqualToString:FACET_DES] ||
        [facet isEqualToString:FACET_DESK] ||
        [facet isEqualToString:FACET_GEO] ||
        [facet isEqualToString:FACET_MATERIAL_TYPE] ||
        [facet isEqualToString:FACET_NYTD_DES] ||
        [facet isEqualToString:FACET_NYTD_GEO] ||
        [facet isEqualToString:FACET_NYTD_ORG] ||
        [facet isEqualToString:FACET_NYTD_PER] ||
        [facet isEqualToString:FACET_NYTD_SECTION] ||
        [facet isEqualToString:FACET_NYTD_WORKS_MENTIONED] ||
        [facet isEqualToString:FACET_ORG] ||
        [facet isEqualToString:FACET_PAGE] ||
        [facet isEqualToString:FACET_PER] ||
        [facet isEqualToString:FACET_PUBLICATION_DAY] ||
        [facet isEqualToString:FACET_PUBLICATION_MONTH] ||
        [facet isEqualToString:FACET_PUBLICATION_YEAR] ||
        [facet isEqualToString:FACET_SECTION_PAGE] ||
        [facet isEqualToString:FACET_SOURCE] ||
        [facet isEqualToString:FACET_WORKS_MENTIONED])
    {
        _name = facet;
        _isReturnFacet = NO;
        return;
    }
    else if(
        [facet isEqualToString:RETURN_CLASSIFIERS] ||
        [facet isEqualToString:RETURN_COLUMN] ||
        [facet isEqualToString:RETURN_DAY_OF_WEEK] ||
        [facet isEqualToString:RETURN_DBPEDIA_RESOURCE] ||
        [facet isEqualToString:RETURN_DBPEDIA_RESOURCE_URL] ||
        [facet isEqualToString:RETURN_DES] ||
        [facet isEqualToString:RETURN_DESK] ||
        [facet isEqualToString:RETURN_GEO] ||
        [facet isEqualToString:RETURN_MATERIAL_TYPE] ||
        [facet isEqualToString:RETURN_NYTD_DES] ||
        [facet isEqualToString:RETURN_NYTD_GEO] ||
        [facet isEqualToString:RETURN_NYTD_ORG] ||
        [facet isEqualToString:RETURN_NYTD_PER] ||
        [facet isEqualToString:RETURN_NYTD_SECTION] ||
        [facet isEqualToString:RETURN_NYTD_WORKS_MENTIONED] ||
        [facet isEqualToString:RETURN_ORG] ||
        [facet isEqualToString:RETURN_PAGE] ||
        [facet isEqualToString:RETURN_PER] ||
        [facet isEqualToString:RETURN_PUBLICATION_DAY] ||
        [facet isEqualToString:RETURN_PUBLICATION_MONTH] ||
        [facet isEqualToString:RETURN_PUBLICATION_YEAR] ||
        [facet isEqualToString:RETURN_SECTION_PAGE] ||
        [facet isEqualToString:RETURN_SOURCE] ||
        [facet isEqualToString:RETURN_WORKS_MENTIONED])
    {
        _name = facet;
        _isReturnFacet = YES;
        return;
    }
     
    [NSException raise:RAISE_INVALID format:FORMAT_INVALID,facet];
}

-(void)setFacetQuery:(NSString*)facetquery
{
    if (_isReturnFacet)
    {
        [NSException raise:RAISE_WRONG_TYPE format:FORMAT_WRONG_TYPE,facetquery];
    }
    
    if (![_name isEqualToString:FACET_DES] ||
        ![_name isEqualToString:FACET_GEO] ||
        ![_name isEqualToString:FACET_ORG] ||
        ![_name isEqualToString:FACET_PER])
    {
        _query = [facetquery uppercaseString];
    }
    else _query = facetquery;
}

-(NSString*)string
{
    return _isReturnFacet ? _name : [_name stringByAppendingFormat:FORMAT_STRING,_query];
}





@end
