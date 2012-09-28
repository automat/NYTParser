//
//  NYTDataTypes.h
//  NYTParser
//
//  Created by Henryk on 27.09.12.
//  Copyright (c) 2012 Henryk. All rights reserved.
//

#ifndef NYTParser_NYTDataTypes_h
#define NYTParser_NYTDataTypes_h

// Data Fields
//
// http://developer.nytimes.com/docs/read/article_search_api#h3-data-fields
//
// Searchable: can be searched using the field:keyword syntax
// -> SEARCH_XXXX
// Facet: must be specified in the facet:[value] syntax
// -> FACET_XXXX
// Information: returned in responses
// -> RETURN_XXXX

// abstract
//
// A summary of the article, written by Times indexers.
// Note: there can be a significant gap (as much as a year) between the publication
// of the article and the writing of the abstract. As an alternative, use body.
//
static NSString* const SEARCH_ABSTRACT = @"abstract";
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
static NSString* const SEARCH_BODY = @"body";
static NSString* const RETURN_BODY = @"body";

// byline
//
// The article byline, including the author's name
//
static NSString* const SEARCH_BYLINE = @"byline";
static NSString* const RETURN_BYLINE = @"byline";

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

// comments
//
// Indicates whether user comments are associated with the article
// (for articles from 2007 to present). To retrieve comments, use the Community API.
//
static NSString* const SEARCH_COMMENTS = @"comments";
static NSString* const RETURN_COMMENTS = @"comments";

// date
//
// The publication date in YYYYMMDD format
//
static NSString* const FACET_DATE  = @"date";
static NSString* const RETURN_DATE = @"date";

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

// facet_terms
//
// Combines des_facet, geo_facet, org_facet and per_facet. Search facet_terms
// to find your query in any of those facets (essentially a combined OR search).
//
// This field is case insensitive (but individual facets are case sensitive).
//
static NSString* const SEARCH_FACET_TERMS = @"facet_terms";

// fee
//
// Indicates whether users must pay a fee to retrieve the full article
//
static NSString* const SEARCH_FEE = @"fee";
static NSString* const RETURN_FEE = @"fee";

// geo_facet
//
// Standardized names of geographic locations, assigned by Times indexers.
// This facet is included in the facet_terms field (see the description in this table).
//
// When used in a request, values must be UPPERCASE
//
static NSString* const FACET_GEO  = @"geo_facet";
static NSString* const RETURN_GEO = @"geo_facet";

// lead_paragraph
//
// The first paragraph of the article (as it appeared in the printed newspaper)
//
static NSString* const SEARCH_LEAD_PARAGRAPH = @"lead_paragraph";
static NSString* const RETURN_LEAD_PARAGRAPH = @"lead_paragraph";

// material_type_facet
//
// The general article type, such as Biography, Editorial or Review
//
static NSString* const FACET_MATERIAL_TYPE  = @"material_type_facet";
static NSString* const RETURN_MATERIAL_TYPE = @"material_type_facet";

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

// nytd_lead_paragraph
//
// The first paragraph of the article (as it appears on NYTimes.com)
//
static NSString* const SEARCH_NYTD_LEAD_PARAGRAPH = @"nytd_lead_paragraph";
static NSString* const RETURN_NYTD_LEAD_PARAGRAPH = @"nytd_lead_paragraph";

// nytd_org_facet
//
// Standardized names of organizations, assigned for use on NYTimes.com
// (to get standardized terms, use the TimesTags API)
//
// When used in a request, values must be Mixed Case
//
static NSString* const FACET_NYTD_ORG = @"nytd_org_facet";
static NSString* const RETURN_NYTD_OG = @"nytd_org_facet";

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

// nytd_title
//
// The article title on NYTimes.com (this field may or may not match the title field;
// headlines may be shortened and edited for the web)
//
static NSString* const EARCH_NYTD_TITLE = @"nytd_title";
static NSString* const RETURN_NYTD_TITLE = @"nytd_title";

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
static NSString* const FACET_PAGE  = @"org_facet";
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
static NSString* const RETURN_PUBLICATION_DAY   = @"publication_day";
static NSString* const FACET_PUBLICATION_MONTH  = @"publication_month";
static NSString* const RETURN_PUBLICATION_MONTH = @"publication_month";
static NSString* const FACET_PUBLICATION_YEAR   = @"publication_year";
static NSString* const RETURN_PUBLICATION_YEAR  = @"publication_year";

// related_media
//
// Indicates whether multimedia features are associated with this article.
// Additional metadata for each related multimedia feature appears in the multimedia array.
// "Multimedia" does not include photos; use the small_image fields for photo metadata
//
static NSString* const SEARCH_RELATED_MEDIA = @"related_media";
static NSString* const RETURN_RELATED_MEDIA = @"related_media";

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

// source_facet
//
// The originating body (e.g., The New York Times or The International Herald Tribune)
//
static NSString* const FACET_SOURCE  = @"source_facet";
static NSString* const RETURN_SOURCE = @"source_facet";

// text
//
// The text field consists of title + byline + body (combined in an OR search)
// and is the default field for keyword searches. For more information, see Constructing a Search Query.
//
static NSString* const SEARCH_TEXT = @"text";

// title
//
// The article title (headline); corresponds to the headline that appeared in the printed newspaper
//
static NSString* const SEARCH_TITLE = @"title";
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

// works_mentioned_facet
//
// Literary works mentioned in the article
//
static NSString* const FACET_WORKS_MENTIONED  = @"works_mentioned_facet";
static NSString* const RETURN_WORKS_MENTIONED = @"works_mentioned_facet";

#endif
