//
//  NYTFacet.h
//  NYTParser
//
//  Created by Henryk on 27.09.12.
//  Copyright (c) 2012 Henryk. All rights reserved.
//

#import <Foundation/Foundation.h>

// classifiers_facet
//
// Taxonomic classifiers that reflect Times content categories, such as Top/News/Sports
//
static NSString* const FACET_CLASSIFIERS  = @"classifiers_facet";
static NSString* const RETURN_CLASSIFIERS = @"classifiers_facet";


// column_facet
//
// A Times column title (if applicable), such as  Weddings or Ideas & Trends
//
static NSString* const FACET_COLUMN  = @"column_facet";
static NSString* const RETURN_COLUMN = @"column_facet";

// date
//
// The publication date in YYYYMMDD format
//
static NSString* const FACET_DATE  = @"date";

// day_of_week_facet
//
// The day of the week (e.g., Monday, Tuesday) the article was published
// (compare publication_day, which is the numeric date rather than the day of the week)
//
static NSString* const FACET_DAY_OF_WEEK  = @"day_of_week_facet";
static NSString* const RETURN_DAY_OF_WEEK = @"day_of_week_facet";

// dbpedia_ressource
//
// DBpedia person names mapped to Times per_facet terms. This field is case sensitive: values must be Mixed Case.
// The Times per_facet is often more comprehensive than dbpedia_resource, but the DBpedia name is easier to use with
// other data sources. For more information about linked open data, see data.nytimes.com.
//

static NSString* const FACET_DBPEDIA_RESOURCE  = @"dbpedia_resource";
static NSString* const RETURN_DBPEDIA_RESOURCE = @"dbpedia_resource";

// dbpedia_resource_url
//
// URLs to DBpedia person names that have been mapped to Times per_facet terms.
// This field is case sensitive: values must be Mixed Case.
// For more information about linked open data, see data.nytimes.com.
//
static NSString* const FACET_DBPEDIA_RESOURCE_URL  = @"dbpedia_resource_url";
static NSString* const RETURN_DBPEDIA_RESOURCE_URL = @"dbpedia_resource_url";

// des_facet
//
// Descriptive subject terms assigned by Times indexers.
// This facet is included in the facet_terms field (see the description in this table).
//
// When used in a request, values must be UPPERCASE
//
static NSString* const FACET_DES  = @"des_facet";
static NSString* const RETURN_DES = @"des_facet";

// desk_facet
//
// The Times desk that produced the story (e.g., Business/Financial Desk)
//
static NSString* const FACET_DESK  = @"desk_facet";
static NSString* const RETURN_DESK = @"desk_facet";

// geo_facet
//
// Standardized names of geographic locations, assigned by Times indexers.
// This facet is included in the facet_terms field (see the description in this table).
//
// When used in a request, values must be UPPERCASE
//
static NSString* const FACET_GEO  = @"geo_facet";
static NSString* const RETURN_GEO = @"geo_facet";

// material_type_facet
//
// The general article type, such as Biography, Editorial or Review
//
static NSString* const FACET_MATERIAL_TYPE  = @"material_type_facet";
static NSString* const RETURN_MATERIAL_TYPE = @"material_type_facet";

// nytd_des_facet
//
// Descriptive subject terms, assigned for use on NYTimes.com
// (to get standardized terms, use the TimesTags API)
//
// When used in a request, values must be Mixed Case
//
static NSString* const FACET_NYTD_DES  = @"nytd_des_facet";
static NSString* const RETURN_NYTD_DES = @"nytd_des_facet";

// nytd_geo_facet
//
// Standardized names of geographic locations, assigned for use on NYTimes.com
// (to get standardized terms, use the TimesTags API)
//
// When used in a request, values must be Mixed Case
//
static NSString* const FACET_NYTD_GEO  = @"nytd_geo_facet";
static NSString* const RETURN_NYTD_GEO = @"nytd_geo_facet";

// nytd_org_facet
//
// Standardized names of organizations, assigned for use on NYTimes.com
// (to get standardized terms, use the TimesTags API)
//
// When used in a request, values must be Mixed Case
//
static NSString* const FACET_NYTD_ORG = @"nytd_org_facet";
static NSString* const RETURN_NYTD_ORG = @"nytd_org_facet";

// nytd_per_facet
//
// Standardized names of people, assigned for use on NYTimes.com
// (to get standardized terms, use the TimesTags API)
//
// When used in a request, values must be Mixed Case
//
static NSString* const FACET_NYTD_PER  = @"nytd_per_facet";
static NSString* const RETURN_NYTD_PER = @"nytd_per_facet";

// nytd_section_facet
//
// The section the article appears in (on NYTimes.com)
//
static NSString* const FACET_NYTD_SECTION  = @"nytd_section_facet";
static NSString* const RETURN_NYTD_SECTION = @"nytd_section_facet";

// nytd_works_mentioned_facet
//
// Literary works mentioned (titles formatted for use on NYTimes.com)
//
static NSString* const FACET_NYTD_WORKS_MENTIONED = @"nytd_works_mentioned_facet";
static NSString* const RETURN_NYTD_WORKS_MENTIONED = @"nytd_works_mentioned_facet";

// org_facet
//
// Standardized names of organizations, assigned by Times indexers.
// This facet is included in the facet_terms field (see the description in this table).
//
// When used in a request, values must be UPPERCASE
//
static NSString* const FACET_ORG  = @"org_facet";
static NSString* const RETURN_ORG = @"org_facet";

// page_facet
//
// The page the article appeared on (in the printed paper)
//
static NSString* const FACET_PAGE  = @"page_facet";
static NSString* const RETURN_PAGE = @"org_facet";

// per_facet
//
// Standardized names of people, assigned by Times indexers.
// This facet is included in the facet_terms field (see the description in this table).
//
// When used in a request, values must be UPPERCASE
//
static NSString* const FACET_PER  = @"per_facet";
static NSString* const RETURN_PER = @"per_facet";

// publication_day publication_month //publication_year
//
// The day (DD), month (MM) and year (YYYY) segments of date, separated for use as facets
//
static NSString* const FACET_PUBLICATION_DAY    = @"publication_day";
static NSString* const FACET_PUBLICATION_MONTH  = @"publication_month";
static NSString* const FACET_PUBLICATION_YEAR   = @"publication_year";
static NSString* const RETURN_PUBLICATION_DAY   = @"publication_day";
static NSString* const RETURN_PUBLICATION_MONTH = @"publication_month";
static NSString* const RETURN_PUBLICATION_YEAR  = @"publication_year";

// section_page_facet
//
// The full page number of the printed article (e.g., D00002).
//
// This data is added to the API 7 days after the article is published.
// Some articles that appear on NYTimes.com do not appear in the printed
// newspaper and thus do not have a value for section_page_facet.
//
static NSString* const FACET_SECTION_PAGE  = @"section_page_facet";
static NSString* const RETURN_SECTION_PAGE = @"section_page_facet";

// source_facet
//
// The originating body (e.g., The New York Times or The International Herald Tribune)
//
static NSString* const FACET_SOURCE  = @"source_facet";
static NSString* const RETURN_SOURCE = @"source_facet";

// works_mentioned_facet
//
// Literary works mentioned in the article
//
static NSString* const FACET_WORKS_MENTIONED  = @"works_mentioned_facet";
static NSString* const RETURN_WORKS_MENTIONED = @"works_mentioned_facet";



@interface NYTFacet : NSObject
{
    @private
    NSString* _name;
    NSString* _query;
    BOOL      _isReturnFacet;
}
@property (nonatomic,readonly) NSString* name;
@property (nonatomic,readonly) NSString* query;
@property (nonatomic,readonly) BOOL isReturnFacet;

-(id)initWithType: (NSString*)fname query:(NSString*)fquery;
-(id)initWithType: (NSString*)fname;
+(id)facetWithType:(NSString*)fname query:(NSString*)fquery;
+(id)facetWithType:(NSString*)fname;
-(NSString*)string;

@end
