//
//  NYTSearchQuery.h
//  NYTParser
//
//  Created by Henryk on 27.09.12.
//  Copyright (c) 2012 Henryk. All rights reserved.
//

#import <Foundation/Foundation.h>

static NSString* const NYT_ARTICLE_SEARCH_API_BASE_URL = @"http://api.nytimes.com/svc/search/v1/article?";

// abstract
//
// A summary of the article, written by Times indexers.
// Note: there can be a significant gap (as much as a year) between the publication
// of the article and the writing of the abstract. As an alternative, use body.
//
static NSString* const FIELD_ABSTRACT  = @"abstract";
static NSString* const RETURN_ABSTRACT = @"abstract";

// author
//
// An author note, such as an e-mail address or short biography (compare byline)
//
static NSString* const SEARCH_AUTHOR = @"author";
static NSString* const RETURN_AUTHOR = @"author";

// body
//
// A portion of the beginning of the article. Note: Only a portion of the article
// body is included in responses. But when you search against the body field,
// you search the full text of the article.
//
static NSString* const FIELD_BODY = @"body";
static NSString* const RETURN_BODY = @"body";

// byline
//
// The article byline, including the author's name
//
static NSString* const FIELD_BYLINE = @"byline";
static NSString* const RETURN_BYLINE = @"byline";

// comments
//
// Indicates whether user comments are associated with the article
// (for articles from 2007 to present). To retrieve comments, use the Community API.
//
static NSString* const SEARCH_COMMENTS = @"comments";
static NSString* const RETURN_COMMENTS = @"comments";

// fee
//
// Indicates whether users must pay a fee to retrieve the full article
//
static NSString* const SEARCH_FEE = @"fee";
static NSString* const RETURN_FEE = @"fee";

// lead_paragraph
//
// The first paragraph of the article (as it appeared in the printed newspaper)
//
static NSString* const SEARCH_LEAD_PARAGRAPH = @"lead_paragraph";
static NSString* const RETURN_LEAD_PARAGRAPH = @"lead_paragraph";

// multimedia
//
// Associated multimedia features (interactive graphics, slideshows, etc.),
// including URLs (see also the related_multimedia field).
// "Multimedia" does not include photos; use the small_image fields for photo metadata.
//
static NSString* const RETURN_MULTIMEDIA = @"multimedia";

// nytd_byline
//
// The article byline, formatted for NYTimes.com
//
static NSString* const SEARCH_NYTD_BYLIEN = @"nytd_byline";
static NSString* const RETURN_NYTD_BYLIEN = @"nytd_byline";

// nytd_title
//
// The article title on NYTimes.com (this field may or may not match the title field;
// headlines may be shortened and edited for the web)
//
static NSString* const EARCH_NYTD_TITLE = @"nytd_title";
static NSString* const RETURN_NYTD_TITLE = @"nytd_title";

// related_media
//
// Indicates whether multimedia features are associated with this article.
// Additional metadata for each related multimedia feature appears in the multimedia array.
// "Multimedia" does not include photos; use the small_image fields for photo metadata
//
static NSString* const SEARCH_RELATED_MEDIA = @"related_media";
static NSString* const RETURN_RELATED_MEDIA = @"related_media";

// small_image small_image_url small_image_height small_image_width
//
// The small_image field indicates whether a thumbnail image
// is associated with the article. The small_image_url field
// provides the URL of the image on NYTimes.com.
// The small_image_height and small_image_width fields provide the image dimensions.
//
static NSString* const SEARCH_SMALL_IMAGE = @"small_image";
static NSString* const RETURN_SMALL_IMAGE = @"small_image";
static NSString* const RETURN_SMALL_IMAGE_URL = @"small_image_url";
static NSString* const RETURN_SMALL_IMAGE_HEIGHT = @"small_image_height";
static NSString* const RETURN_SMALL_IMAGE_WIDTH = @"small_image_width";

// text
//
// The text field consists of title + byline + body (combined in an OR search)
// and is the default field for keyword searches. For more information, see Constructing a Search Query.
//
static NSString* const FIELD_TEXT = @"text";

// title
//
// The article title (headline); corresponds to the headline that appeared in the printed newspaper
//
static NSString* const FIELD_TITLE = @"title";
static NSString* const RETURN_TITLE = @"title";

// tokens
//
// Your query terms, returned for your reference
//
static NSString* const RETURN_TOKENS = @"tokens";

// url
//
// The URL of the article on NYTimes.com
//
static NSString* const SEARCH_URL = @"url";
static NSString* const RETURN_URL = @"url";

// word_count
//
// The full article word count
//
static NSString* const RETURN_WORD_COUNT = @"word_count";


static NSString* const RANK_NEWEST  = @"newest";
static NSString* const RANK_OLDEST  = @"oldest";
static NSString* const RANK_CLOSEST = @"closest";

@class NYTFacet;

@interface NYTArticleSearchQuery : NSObject
{
    @private
    
    BOOL _searchSet;
    BOOL _excludeSet;
    BOOL _facetesSet;
    BOOL _returnFacetesSet;
    BOOL _returnFieldsSet;
    
    NSMutableString* _queryKeywords;
    NSMutableString* _queryExcludes;
    NSMutableString* _queryFacets;
    NSMutableString* _queryReturnFields;
    NSMutableString* _queryReturnFacets;
    
    NSString* _paramBeginDate;
    NSString* _paramEndDate;
    
    int _offset;
    
    NSString* _apikey;
}

+(id)query;

-(void)setOffset:(int)offset;

-(void)setDateBegin:(NSString*)yyyymmdd;
-(void)setDateEnd:(NSString*)yyyymmdd;

-(void)searchKeywords:(NSString*)firstKeyword,... NS_REQUIRES_NIL_TERMINATION;
-(void)search: (NSString*)field keywords:(NSString*)firstKeyword,... NS_REQUIRES_NIL_TERMINATION;
-(void)excludeKeywords:(NSString*)firstKeyword,... NS_REQUIRES_NIL_TERMINATION;
-(void)exclude:(NSString*)field keywords:(NSString*)firstKeyword,... NS_REQUIRES_NIL_TERMINATION;

-(void)addFacetes:(NYTFacet*)firstFacete,... NS_REQUIRES_NIL_TERMINATION;
-(void)addReturnFields:(NSString*)firstReturnField,... NS_REQUIRES_NIL_TERMINATION;
-(void)addReturnFacets:(NYTFacet*)firstReturnFacet,... NS_REQUIRES_NIL_TERMINATION;

-(NSString*)resultQuery;
-(NSString*)requestURL;

@end
