//
//  NYTSearchQuery.m
//  NYTParser
//
//  Created by Henryk on 27.09.12.
//  Copyright (c) 2012 Henryk. All rights reserved.
//

#import "NYTArticleSearchQuery.h"
#import "NYTKeys.h"
#import "NYTArticleSearchQuery.h"
#import "NYTFacet.h"

static NSString* const QUERY        = @"query=";
static NSString* const FIELDS       = @"&fields=";
static NSString* const RETURN_FACET = @"&facets=";
static NSString* const API_KEY = @"&api-key=";

static NSString* const PREFIX_EXCLUDE = @"-";
static NSString* const PREFIX_EMPTY   = @"";
static NSString* const PREFIX_SPACE = @" ";

static NSString* const PREFIX_FIELD_TEXT     = @"text:";
static NSString* const PREFIX_FIELD_TITLE    = @"title:";
static NSString* const PREFIX_FIELD_ABSTRACT = @"abstract:";
static NSString* const PREFIX_FIELD_BODY     = @"body:";
static NSString* const PREFIX_FIELD_BYLINE   = @"byline:";




static NSString* const SEPERATOR_SPACE = @" ";
static NSString* const SEPERATOR_COMMA = @",";

static NSString* const EMPTY_STRING = @"";

static NSString* const PARAM_BEGIN_DATE = @"&begin_date=";
static NSString* const PARAM_END_DATE   = @"&end_date=";
static NSString* const PARAM_OFFSET     = @"&offset=";
static NSString* const PARAM_EMPTY = @"";

static NSString* const RAISE_INVALID_FACET         = @"Invalid Facet";
static NSString* const FORMAT_INVALID_FACET        = @"Format of facet %@ is not of type return";
static NSString* const RAISE_INVALID_FIELD         = @"Invalid Field";
static NSString* const FORMAT_INVALID_FIELD        = @"Format of field %@ is invalid";
static NSString* const RAISE_INVALID_DATE          = @"Invalid Date";
static NSString* const FORMAT_INVALID_DATE         = @"Format of date %@ is invalid. Format is YYYYMMDD";
static NSString* const RAISE_INVALID_RETURN_FIELD  = @"Invalid Return-Field";
static NSString* const FORMAT_INVALID_RETURN_FIELD = @"Format of field %@ is invalid";

static NSString* const FORMAT_FIRST_ARG = @"%@%@";
static NSString* const FORMAT_EACH_ARG  = @"%@%@%@";

@implementation NYTArticleSearchQuery

#pragma mark ---- Init ----

-(id)init
{
    if(self =  [super init])
    {
        _searchSet        = NO;
        _excludeSet       = NO;
        _facetesSet       = NO;
        _returnFacetesSet = NO;
        _returnFieldsSet  = NO;
        
        _queryKeywords     = [NSMutableString string];
        _queryExcludes     = [NSMutableString string];
        _queryFacets       = [NSMutableString string];
        _queryReturnFields = [NSMutableString string];
        _queryReturnFacets = [NSMutableString string];
        
        _paramBeginDate = [NSString string];
        _paramEndDate   = [NSString string];
        
        _offset = -1;
        _apikey = [NSString stringWithFormat:@"%@%@",API_KEY,NYT_API_ARTICLE_SEARCH_KEY];
    }
    return self;
}

+(id)query
{
    return [[NYTArticleSearchQuery alloc] init];
}

#pragma mark ---- Offset ----

-(void)setOffset:(int)offset
{
    _offset = offset;
}

#pragma mark ---- Begin and End Date ----

-(void)setDateBegin:(NSString *)yyyymmdd
{
    if (![self dateIsValid:yyyymmdd])
    {
        [NSException raise:RAISE_INVALID_DATE format:FORMAT_INVALID_DATE,yyyymmdd];
    }
    
    _paramBeginDate = yyyymmdd;
}

-(void)setDateEnd:(NSString *)yyyymmdd
{
    if (![self dateIsValid:yyyymmdd])
    {
        [NSException raise:RAISE_INVALID_DATE format:FORMAT_INVALID_DATE,yyyymmdd];
    }
    
    _paramEndDate = yyyymmdd;
}

#pragma mark ---- Search Keywords ----

-(void)searchKeywords:(NSString*)firstKeyword,... NS_REQUIRES_NIL_TERMINATION
{
    va_list args;
    va_start(args, firstKeyword);
    
    [self setString:_queryKeywords
             format:firstKeyword
          arguments:args
             prefix: _searchSet ? PREFIX_FIELD_TEXT : PREFIX_EMPTY
          seperator:SEPERATOR_SPACE firstSeperator:_searchSet ? PREFIX_SPACE : nil];
    
    va_end(args);
    _searchSet = YES;
}

-(void)search:(NSString*)field keywords:(NSString*)firstKeyword,... NS_REQUIRES_NIL_TERMINATION
{
    if(![self fieldIsValid:field])
    {
        [NSException raise:RAISE_INVALID_FIELD format:FORMAT_INVALID_FIELD,field];
    }
    
    NSString* prefix = [self prefixForField:field];
      
    va_list args;
    va_start(args,firstKeyword);
        
    [self setString:_queryKeywords
             format:firstKeyword
          arguments:args
             prefix:prefix
          seperator:SEPERATOR_SPACE
     firstSeperator:_searchSet ? SEPERATOR_SPACE : nil];
        
     va_end(args);
     _searchSet = YES;
}

#pragma mark ---- Exclude Keywords ----

-(void)excludeKeywords:(NSString *)firstKeyword, ... NS_REQUIRES_NIL_TERMINATION
{
    va_list args;
    va_start(args, firstKeyword);
    
    NSString* excludePrefix = _excludeSet ? [self excludePrefixForField:FIELD_TEXT] : PREFIX_EXCLUDE;
    
    [self setString:_queryKeywords
             format:firstKeyword
          arguments:args
             prefix: excludePrefix
          seperator:SEPERATOR_SPACE
     firstSeperator:_excludeSet ? SEPERATOR_SPACE : nil];
    
    va_end(args);
    _excludeSet = YES;
    
}

-(void)exclude:(NSString *)field keywords:(NSString *)firstKeyword, ... NS_REQUIRES_NIL_TERMINATION
{
    if(![self fieldIsValid:field])
    {
        [NSException raise:RAISE_INVALID_FIELD format:FORMAT_INVALID_FIELD,field];
    }
    
    NSString* prefix = [PREFIX_EXCLUDE stringByAppendingString:[self prefixForField:field]];
        
    va_list args;
    va_start(args, firstKeyword);
        
    [self setString:_queryKeywords
             format:firstKeyword
          arguments:args
             prefix:prefix
          seperator:SEPERATOR_SPACE
     firstSeperator:_excludeSet ? SEPERATOR_SPACE : nil];
        
    va_end(args);
    _excludeSet = YES;
        
    return;
}



-(void)addFacetes:(NYTFacet*)firstFacete,... NS_REQUIRES_NIL_TERMINATION
{
    va_list args;
    va_start(args, firstFacete);
  
    [self setString:_queryFacets
             format:firstFacete
          arguments:args
             prefix:PREFIX_EMPTY
          seperator:SEPERATOR_SPACE
     firstSeperator:_facetesSet ? SEPERATOR_SPACE : nil];
    
    va_end(args);
    _facetesSet = YES;
}

-(void)addReturnFields:(NSString *)firstReturnField, ...
{
    if (![self returnFieldIsValid:firstReturnField])
    {
        [NSException raise:RAISE_INVALID_RETURN_FIELD format:FORMAT_INVALID_RETURN_FIELD,firstReturnField];
    }
    
    
    _returnFieldsSet = YES;
}

-(void)addReturnFacets:(NYTFacet*)firstReturnFacet,... NS_REQUIRES_NIL_TERMINATION
{
    if (![firstReturnFacet isReturnFacet])
    {
        [NSException raise:RAISE_INVALID_FACET format:FORMAT_INVALID_FACET,firstReturnFacet.name];
    }
    
    va_list args;
    va_start(args, firstReturnFacet);
   
    [self setString:_queryReturnFacets
             format:firstReturnFacet
          arguments:args
             prefix:PREFIX_EMPTY
          seperator:SEPERATOR_COMMA
     firstSeperator:nil];
   
    va_end(args);
    
    _returnFacetesSet = YES;
    
}

#pragma mark ---- construct query parts ----

-(void)setString:(NSMutableString*)string format:(id)firstArg arguments:(va_list)list prefix:(NSString*)prefix seperator:(NSString*)seperator firstSeperator:(NSString*)firstSeperator
{
    BOOL formatIsFacet       = [firstArg isMemberOfClass:[NYTFacet class]];
    BOOL formatIsReturnFacet = formatIsFacet && [firstArg isReturnFacet];
    
    NSString* first = [self ANDStringFromString:formatIsFacet ? [(NYTFacet*)firstArg string] : firstArg];
    [string appendFormat:FORMAT_FIRST_ARG,prefix ? (firstSeperator ? [firstSeperator stringByAppendingString:prefix] : prefix) :
     (firstSeperator ? [firstSeperator stringByAppendingString:PREFIX_EMPTY] : PREFIX_EMPTY)
     ,first];
    
    id eachArg;
    
    while (eachArg = va_arg(list, id))
    {
        if (formatIsReturnFacet && ![(NYTFacet*)eachArg isReturnFacet])
        {
            [NSException raise:RAISE_INVALID_FACET format:FORMAT_INVALID_FACET,[(NYTFacet*)eachArg name]];
        }
        
        [string appendFormat:FORMAT_EACH_ARG,seperator,prefix,formatIsFacet ? [(NYTFacet*)eachArg string] :
         [self ANDStringFromString:eachArg]];
    }
}

#pragma mark ---- String Methods ----

-(NSString*)ANDStringFromString:(NSString*)string
{
    NSRange whitespace = [string rangeOfString:@" "];
    return whitespace.length > 0 ? [NSString stringWithFormat:@"\"%@\"",string] : string;
}

-(NSString*)excludeString:(NSString*)string
{
    return [@"-" stringByAppendingString:string];
}

#pragma mark ---- Field Methods ----

-(NSString*)prefixForField:(NSString*)field
{
    return [field isEqualToString:FIELD_ABSTRACT] ? PREFIX_FIELD_ABSTRACT :
    [field isEqualToString:FIELD_TITLE]    ? PREFIX_FIELD_TITLE :
    [field isEqualToString:FIELD_BODY]     ? PREFIX_FIELD_BODY :
    [field isEqualToString:FIELD_BYLINE]   ? PREFIX_FIELD_BYLINE :
    [field isEqualToString:FIELD_TEXT]     ? PREFIX_EMPTY :
    PREFIX_EMPTY;
}

-(NSString*)excludePrefixForField:(NSString*)field
{
    return [PREFIX_EXCLUDE stringByAppendingString:[self prefixForField:field]];
}

#pragma mark ---- validate Fields ----

-(BOOL)dateIsValid:(NSString*)date
{
    return date.length != 6;
}

-(BOOL)fieldIsValid:(NSString*)field
{
    return [field isEqualToString:FIELD_ABSTRACT] ||
           [field isEqualToString:FIELD_TITLE] ||
           [field isEqualToString:FIELD_BODY]||
           [field isEqualToString:FIELD_TEXT] ||
           [field isEqualToString:FIELD_BYLINE];
}

-(BOOL)returnFieldIsValid:(NSString*)returnField
{
    return [returnField isEqualToString:RETURN_ABSTRACT] ||
           [returnField isEqualToString:RETURN_AUTHOR] ||
           [returnField isEqualToString:RETURN_BODY] ||
           [returnField isEqualToString:RETURN_BYLINE] ||
           [returnField isEqualToString:RETURN_CLASSIFIERS] ||
           [returnField isEqualToString:RETURN_COLUMN] ||
           [returnField isEqualToString:RETURN_COMMENTS] ||
           [returnField isEqualToString:RETURN_DAY_OF_WEEK] ||
           [returnField isEqualToString:RETURN_DBPEDIA_RESOURCE] ||
           [returnField isEqualToString:RETURN_DBPEDIA_RESOURCE_URL] ||
           [returnField isEqualToString:RETURN_DES] ||
           [returnField isEqualToString:RETURN_DESK] ||
           [returnField isEqualToString:RETURN_FACET] ||
           [returnField isEqualToString:RETURN_FEE] ||
           [returnField isEqualToString:RETURN_GEO] ||
           [returnField isEqualToString:RETURN_LEAD_PARAGRAPH] ||
           [returnField isEqualToString:RETURN_MATERIAL_TYPE] ||
           [returnField isEqualToString:RETURN_MULTIMEDIA] ||
           [returnField isEqualToString:RETURN_NYTD_BYLIEN] ||
           [returnField isEqualToString:RETURN_NYTD_DES] ||
           [returnField isEqualToString:RETURN_NYTD_GEO] ||
           [returnField isEqualToString:RETURN_NYTD_ORG] ||
           [returnField isEqualToString:RETURN_NYTD_PER] ||
           [returnField isEqualToString:RETURN_NYTD_SECTION] ||
           [returnField isEqualToString:RETURN_NYTD_TITLE] ||
           [returnField isEqualToString:RETURN_NYTD_WORKS_MENTIONED] ||
           [returnField isEqualToString:RETURN_ORG] ||
           [returnField isEqualToString:RETURN_PAGE] ||
           [returnField isEqualToString:RETURN_PER] ||
           [returnField isEqualToString:RETURN_PUBLICATION_DAY] ||
           [returnField isEqualToString:RETURN_PUBLICATION_MONTH] ||
           [returnField isEqualToString:RETURN_PUBLICATION_YEAR] ||
           [returnField isEqualToString:RETURN_RELATED_MEDIA] ||
           [returnField isEqualToString:RETURN_SECTION_PAGE] ||
           [returnField isEqualToString:RETURN_SMALL_IMAGE] ||
           [returnField isEqualToString:RETURN_SMALL_IMAGE_HEIGHT] ||
           [returnField isEqualToString:RETURN_SMALL_IMAGE_URL] ||
           [returnField isEqualToString:RETURN_SMALL_IMAGE_WIDTH] ||
           [returnField isEqualToString:RETURN_SOURCE] ||
           [returnField isEqualToString:RETURN_TITLE] ||
           [returnField isEqualToString:RETURN_TOKENS] ||
           [returnField isEqualToString:RETURN_URL] ||
           [returnField isEqualToString:RETURN_WORD_COUNT] ||
           [returnField isEqualToString:RETURN_WORKS_MENTIONED];
}

#pragma mark ---- query build ----

-(NSString*)resultQuery
{
    NSMutableString* result = [NSMutableString string];
    
    NSString* keywords = _queryKeywords;
    
    NSString* excludes = _queryExcludes.length > 0 ?
                        [@"" stringByAppendingFormat:@"%@%@", SEPERATOR_SPACE,_queryExcludes] :
                        EMPTY_STRING;
    
    NSString* facets   = _queryFacets.length > 0 ?
                        [@"" stringByAppendingFormat:@"%@%@", SEPERATOR_SPACE,_queryFacets] :
                        EMPTY_STRING;
    
    NSString* rfacets  = _queryReturnFacets.length > 0 ?
                        [@"" stringByAppendingFormat:@"%@%@", RETURN_FACET,   _queryReturnFacets] :
                        EMPTY_STRING;
    
    NSString* rfields  = _queryReturnFields.length > 0 ?
                        [@"" stringByAppendingFormat:@"%@%@", SEPERATOR_COMMA,_queryReturnFields] :
                        EMPTY_STRING;
    
    NSString* pBDate   = _paramBeginDate.length > 0 ?
                        [@"" stringByAppendingFormat:@"%@%@", PARAM_BEGIN_DATE,_paramBeginDate ] :
                        EMPTY_STRING;
    
    NSString* pEDate   = _paramEndDate.length > 0 ?
                        [@"" stringByAppendingFormat:@"%@%@", PARAM_END_DATE,_paramEndDate ] :
                        EMPTY_STRING;
    
    
    [result appendFormat:@"%@%@%@%@%@%@%@%@%@",QUERY,keywords,excludes,facets,rfacets,rfields,pBDate,pEDate,_apikey];
  
    return result;
}

#pragma mark ---- request url ----

-(NSString*)requestURL
{
    NSString* s = [NYT_ARTICLE_SEARCH_API_BASE_URL stringByAppendingString:[self resultQuery]];
    
    NSLog(@"%@",s);
    
    return [s stringByAddingPercentEscapesUsingEncoding:NSUTF8StringEncoding];
}

@end
