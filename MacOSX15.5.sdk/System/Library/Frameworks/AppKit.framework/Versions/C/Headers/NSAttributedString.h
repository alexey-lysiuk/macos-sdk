#if (defined(USE_APPKIT_PUBLIC_HEADERS) && USE_APPKIT_PUBLIC_HEADERS) || !__has_include(<UIFoundation/NSAttributedString.h>)
#include <TargetConditionals.h>

#if !TARGET_OS_IPHONE
#import <AppKit/AppKitDefines.h>

/*
        NSAttributedString.h
        Copyright (c) 1994-2024, Apple Inc.
        All rights reserved.
 
        This file defines Application Kit extensions to NSAttributedString and NSMutableAttributedString.
*/

#import <Foundation/NSAttributedString.h>

@class NSAttributedString;
@class NSFileWrapper;
@class NSURL;

NS_HEADER_AUDIT_BEGIN(nullability, sendability)

/************************ Attributes ************************/

// Predefined character attributes for text. If the key is not present in the dictionary, it indicates the default value described below.
APPKIT_EXTERN NSAttributedStringKey NSFontAttributeName API_AVAILABLE(macos(10.0), ios(6.0), tvos(9.0), watchos(2.0), visionos(1.0));                // UIFont, default Helvetica(Neue) 12
APPKIT_EXTERN NSAttributedStringKey NSParagraphStyleAttributeName API_AVAILABLE(macos(10.0), ios(6.0), tvos(9.0), watchos(2.0), visionos(1.0));      // NSParagraphStyle, default defaultParagraphStyle
APPKIT_EXTERN NSAttributedStringKey NSForegroundColorAttributeName API_AVAILABLE(macos(10.0), ios(6.0), tvos(9.0), watchos(2.0), visionos(1.0));     // UIColor, default blackColor
APPKIT_EXTERN NSAttributedStringKey NSBackgroundColorAttributeName API_AVAILABLE(macos(10.0), ios(6.0), tvos(9.0), watchos(2.0), visionos(1.0));     // UIColor, default nil: no background
APPKIT_EXTERN NSAttributedStringKey NSLigatureAttributeName API_AVAILABLE(macos(10.0), ios(6.0), tvos(9.0), watchos(2.0), visionos(1.0));            // NSNumber containing integer, default 1: default ligatures, 0: no ligatures
APPKIT_EXTERN NSAttributedStringKey NSKernAttributeName API_AVAILABLE(macos(10.0), ios(6.0), tvos(9.0), watchos(2.0), visionos(1.0));                // NSNumber containing floating point value, in points; amount to modify default kerning. 0 means kerning is disabled.
APPKIT_EXTERN NSAttributedStringKey NSTrackingAttributeName API_AVAILABLE(macos(11.0), ios(14.0), watchos(7.0), tvos(14.0), visionos(1.0));          // NSNumber containing floating point value, in points; amount to modify default tracking. 0 means tracking is disabled.
APPKIT_EXTERN NSAttributedStringKey NSStrikethroughStyleAttributeName API_AVAILABLE(macos(10.0), ios(6.0), tvos(9.0), watchos(2.0), visionos(1.0));  // NSNumber containing integer, default 0: no strikethrough
APPKIT_EXTERN NSAttributedStringKey NSUnderlineStyleAttributeName API_AVAILABLE(macos(10.0), ios(6.0), tvos(9.0), watchos(2.0), visionos(1.0));      // NSNumber containing integer, default 0: no underline
APPKIT_EXTERN NSAttributedStringKey NSStrokeColorAttributeName API_AVAILABLE(macos(10.0), ios(6.0), tvos(9.0), watchos(2.0), visionos(1.0));         // UIColor, default nil: same as foreground color
APPKIT_EXTERN NSAttributedStringKey NSStrokeWidthAttributeName API_AVAILABLE(macos(10.0), ios(6.0), tvos(9.0), watchos(2.0), visionos(1.0));         // NSNumber containing floating point value, in percent of font point size, default 0: no stroke; positive for stroke alone, negative for stroke and fill (a typical value for outlined text would be 3.0)
APPKIT_EXTERN NSAttributedStringKey NSShadowAttributeName API_AVAILABLE(macos(10.0), ios(6.0), tvos(9.0), watchos(2.0), visionos(1.0));              // NSShadow, default nil: no shadow
APPKIT_EXTERN NSAttributedStringKey const NSTextEffectAttributeName API_AVAILABLE(macos(10.10), ios(6.0), tvos(9.0), watchos(2.0), visionos(1.0));          // NSString, default nil: no text effect

APPKIT_EXTERN NSAttributedStringKey NSAttachmentAttributeName API_AVAILABLE(macos(10.0), ios(7.0), tvos(9.0), watchos(2.0), visionos(1.0));          // NSTextAttachment, default nil
APPKIT_EXTERN NSAttributedStringKey NSLinkAttributeName API_AVAILABLE(macos(10.0), ios(7.0), tvos(9.0), watchos(2.0), visionos(1.0));                // NSURL (preferred) or NSString
APPKIT_EXTERN NSAttributedStringKey NSBaselineOffsetAttributeName API_AVAILABLE(macos(10.0), ios(7.0), tvos(9.0), watchos(2.0), visionos(1.0));      // NSNumber containing floating point value, in points; offset from baseline, default 0
APPKIT_EXTERN NSAttributedStringKey NSUnderlineColorAttributeName API_AVAILABLE(macos(10.0), ios(7.0), tvos(9.0), watchos(2.0), visionos(1.0));      // UIColor, default nil: same as foreground color
APPKIT_EXTERN NSAttributedStringKey NSStrikethroughColorAttributeName API_AVAILABLE(macos(10.0), ios(7.0), tvos(9.0), watchos(2.0), visionos(1.0));  // UIColor, default nil: same as foreground color

APPKIT_EXTERN NSAttributedStringKey NSWritingDirectionAttributeName API_AVAILABLE(macos(10.6), ios(6.0), tvos(9.0), watchos(2.0), visionos(1.0));    // NSArray of NSNumbers representing the nested levels of writing direction overrides as defined by Unicode LRE, RLE, LRO, and RLO characters.  The control characters can be obtained by masking NSWritingDirection and NSWritingDirectionFormatType values.  LRE: NSWritingDirectionLeftToRight|NSWritingDirectionEmbedding, RLE: NSWritingDirectionRightToLeft|NSWritingDirectionEmbedding, LRO: NSWritingDirectionLeftToRight|NSWritingDirectionOverride, RLO: NSWritingDirectionRightToLeft|NSWritingDirectionOverride,

// NSTextHighlightStyleAttributeName is a character-level NSAttributedStringKey for decorating a section of text highlighted for emphasis.
APPKIT_EXTERN NSAttributedStringKey const NSTextHighlightStyleAttributeName API_AVAILABLE(macos(15.0), ios(18.0), tvos(18.0), watchos(11.0), visionos(2.0)); // NSTextHighlightStyle, default nil: no highlight

// NSTextHighlightColorSchemeAttributeName is a character-level NSAttributedStringKey for specifying the color scheme used by NSTextHighlightStyleAttributeName at the same range.
APPKIT_EXTERN NSAttributedStringKey const NSTextHighlightColorSchemeAttributeName API_AVAILABLE(macos(15.0), ios(18.0), tvos(18.0), watchos(11.0), visionos(2.0)); // The default color scheme. The color is based on the tint/accent color for the rendering context. By default UIKit uses UIView.tintColor and AppKit uses NSColor.controlAccentColor.

APPKIT_EXTERN NSAttributedStringKey const NSAdaptiveImageGlyphAttributeName API_AVAILABLE(macos(15.0), ios(18.0), tvos(18.0), watchos(11.0), visionos(2.0)); // NSAdaptiveImageGlyph, default nil

// NSNumber (Boolean) value. Default is false. The range of text with NSWritingToolsExclusionAttributeName=true is excluded from the WritingTools processing and preserved.
APPKIT_EXTERN NSAttributedStringKey const NSWritingToolsExclusionAttributeName API_AVAILABLE(ios(18.2), macos(15.2)) API_UNAVAILABLE(visionos, tvos, watchos);

/************************ Attribute values ************************/
// This defines currently supported values for NSUnderlineStyleAttributeName and NSStrikethroughStyleAttributeName. These values are or'ed together to produce an underline style.
// Underlines will be drawn with a solid pattern by default, so NSUnderlineStylePatternSolid does not need to be specified.
typedef NS_OPTIONS(NSInteger, NSUnderlineStyle) {
    NSUnderlineStyleNone                                    = 0x00,
    NSUnderlineStyleSingle                                  = 0x01,
    NSUnderlineStyleThick API_AVAILABLE(macos(10.0), ios(7.0), tvos(9.0), watchos(2.0), visionos(1.0))      = 0x02,
    NSUnderlineStyleDouble API_AVAILABLE(macos(10.0), ios(7.0), tvos(9.0), watchos(2.0), visionos(1.0))     = 0x09,

    NSUnderlineStylePatternSolid API_AVAILABLE(macos(10.0), ios(7.0), tvos(9.0), watchos(2.0), visionos(1.0))      = 0x0000,
    NSUnderlineStylePatternDot API_AVAILABLE(macos(10.0), ios(7.0), tvos(9.0), watchos(2.0), visionos(1.0))        = 0x0100,
    NSUnderlineStylePatternDash API_AVAILABLE(macos(10.0), ios(7.0), tvos(9.0), watchos(2.0), visionos(1.0))       = 0x0200,
    NSUnderlineStylePatternDashDot API_AVAILABLE(macos(10.0), ios(7.0), tvos(9.0), watchos(2.0), visionos(1.0))    = 0x0300,
    NSUnderlineStylePatternDashDotDot API_AVAILABLE(macos(10.0), ios(7.0), tvos(9.0), watchos(2.0), visionos(1.0)) = 0x0400,

    NSUnderlineStyleByWord API_AVAILABLE(macos(10.0), ios(7.0), tvos(9.0), watchos(2.0), visionos(1.0))            = 0x8000
} API_AVAILABLE(macos(10.0), ios(6.0), tvos(9.0), watchos(2.0), visionos(1.0));

// NSWritingDirectionFormatType values used by NSWritingDirectionAttributeName. It is or'ed with either NSWritingDirectionLeftToRight or NSWritingDirectionRightToLeft. Can specify the formatting controls defined by Unicode Bidirectional Algorithm.
typedef NS_ENUM(NSInteger, NSWritingDirectionFormatType) {
    NSWritingDirectionEmbedding     = (0 << 1),
    NSWritingDirectionOverride      = (1 << 1)
} API_AVAILABLE(macos(10.11), ios(9.0), tvos(9.0), watchos(2.0), visionos(1.0));

// NSTextEffectAttributeName values
typedef NSString * NSTextEffectStyle NS_TYPED_ENUM API_AVAILABLE(macos(10.10), ios(7.0), tvos(9.0), watchos(2.0), visionos(1.0));
APPKIT_EXTERN NSTextEffectStyle const NSTextEffectLetterpressStyle API_AVAILABLE(macos(10.10), ios(7.0), tvos(9.0), watchos(2.0), visionos(1.0));

// NSTextHighlightStyleAttributeName values
typedef NSString * NSTextHighlightStyle NS_TYPED_EXTENSIBLE_ENUM API_AVAILABLE(macos(15.0), ios(18.0), tvos(18.0), watchos(11.0), visionos(2.0));
APPKIT_EXTERN NSTextHighlightStyle const NSTextHighlightStyleDefault API_AVAILABLE(macos(15.0), ios(18.0), tvos(18.0), watchos(11.0), visionos(2.0)); // The system-defined default highlight type. Supported only with TextKit2

// NSTextHighlightColorSchemeAttributeName values
typedef NSString * NSTextHighlightColorScheme NS_TYPED_EXTENSIBLE_ENUM API_AVAILABLE(macos(15.0), ios(18.0), tvos(18.0), watchos(11.0), visionos(2.0));
APPKIT_EXTERN NSTextHighlightColorScheme const NSTextHighlightColorSchemeDefault API_AVAILABLE(macos(15.0), ios(18.0), tvos(18.0), watchos(11.0), visionos(2.0)); // The system-defined default highlight type. Supported only with TextKit2
APPKIT_EXTERN NSTextHighlightColorScheme const NSTextHighlightColorSchemePurple API_AVAILABLE(macos(15.0), ios(18.0), tvos(18.0), watchos(11.0), visionos(2.0));
APPKIT_EXTERN NSTextHighlightColorScheme const NSTextHighlightColorSchemePink API_AVAILABLE(macos(15.0), ios(18.0), tvos(18.0), watchos(11.0), visionos(2.0));
APPKIT_EXTERN NSTextHighlightColorScheme const NSTextHighlightColorSchemeOrange API_AVAILABLE(macos(15.0), ios(18.0), tvos(18.0), watchos(11.0), visionos(2.0));
APPKIT_EXTERN NSTextHighlightColorScheme const NSTextHighlightColorSchemeMint API_AVAILABLE(macos(15.0), ios(18.0), tvos(18.0), watchos(11.0), visionos(2.0));
APPKIT_EXTERN NSTextHighlightColorScheme const NSTextHighlightColorSchemeBlue API_AVAILABLE(macos(15.0), ios(18.0), tvos(18.0), watchos(11.0), visionos(2.0));


/************************ Attribute fixing ************************/

@interface NSMutableAttributedString (NSAttributedStringAttributeFixing)
// This method fixes attribute inconsistencies inside range.  It ensures NSFontAttributeName covers the characters, NSParagraphStyleAttributeName is only changing at paragraph boundaries, and NSTextAttachmentAttributeName is assigned to NSAttachmentCharacter.  NSTextStorage automatically invokes this method via -ensureAttributesAreFixedInRange:.
- (void)fixAttributesInRange:(NSRange)range API_AVAILABLE(macos(10.0), ios(7.0), tvos(9.0), watchos(2.0), visionos(1.0));

@end


/************************ Document formats ************************/

typedef NSString * NSAttributedStringDocumentType NS_TYPED_EXTENSIBLE_ENUM API_AVAILABLE(macos(10.0), ios(7.0), tvos(9.0), watchos(2.0), visionos(1.0));

// Supported document types for the NSDocumentTypeDocumentAttribute key in the document attributes dictionary.
APPKIT_EXTERN NSAttributedStringDocumentType NSPlainTextDocumentType API_AVAILABLE(macos(10.0), ios(7.0), tvos(9.0), watchos(2.0), visionos(1.0));
APPKIT_EXTERN NSAttributedStringDocumentType NSRTFTextDocumentType  API_AVAILABLE(macos(10.0), ios(7.0), tvos(9.0), watchos(2.0), visionos(1.0));
APPKIT_EXTERN NSAttributedStringDocumentType NSRTFDTextDocumentType API_AVAILABLE(macos(10.0), ios(7.0), tvos(9.0), watchos(2.0), visionos(1.0));
APPKIT_EXTERN NSAttributedStringDocumentType NSHTMLTextDocumentType  API_AVAILABLE(macos(10.0), ios(7.0), tvos(9.0), watchos(2.0), visionos(1.0));

typedef NSString * NSTextLayoutSectionKey NS_TYPED_ENUM API_AVAILABLE(macos(10.7), ios(6.0), tvos(9.0), watchos(2.0), visionos(1.0));

// Keys for NSLayoutOrientationSectionsAttribute.
APPKIT_EXTERN NSTextLayoutSectionKey NSTextLayoutSectionOrientation API_AVAILABLE(macos(10.7), ios(6.0), tvos(9.0), watchos(2.0), visionos(1.0)); // NSNumber containing NSTextLayoutOrientation value. default: NSTextLayoutOrientationHorizontal
APPKIT_EXTERN NSTextLayoutSectionKey NSTextLayoutSectionRange API_AVAILABLE(macos(10.7), ios(6.0), tvos(9.0), watchos(2.0), visionos(1.0)); // NSValue containing NSRange representing a character range. default: a range covering the whole document

// Supported values for NSTextScalingDocumentAttribute, NSSourceTextScalingDocumentAttribute, NSTargetTextScalingDocumentOption, NSSourceTextScalingDocumentOption
typedef NS_ENUM(NSInteger, NSTextScalingType) {
    NSTextScalingStandard = 0,  // Font sizes throughout the document should appear visually similar to how they would render on macOS and non-Apple platforms
    NSTextScalingiOS  // Font sizes throughout the document should appear visually similar to how they would render on iOS
} API_AVAILABLE(macos(10.15), ios(13.0), watchos(6.0), tvos(13.0), visionos(1.0));

typedef NSString * NSAttributedStringDocumentAttributeKey NS_TYPED_EXTENSIBLE_ENUM API_AVAILABLE(macos(10.0), ios(7.0), tvos(9.0), watchos(2.0), visionos(1.0));

// Keys for options and document attributes dictionaries.  They are in and out document properties used by both read/write methods.

APPKIT_EXTERN NSAttributedStringDocumentAttributeKey NSDocumentTypeDocumentAttribute API_AVAILABLE(macos(10.0), ios(7.0), tvos(9.0), watchos(2.0), visionos(1.0));  // @"DocumentType", one of the document types declared above.  For reader methods, this key in options can specify the document type for interpreting the contents.  Upon return, the document attributes can contain this key for indicating the actual format used to read the contents.  For write methods, this key specifies the format for generating the data.


// NSPlainTextDocumentType document attributes
APPKIT_EXTERN NSAttributedStringDocumentAttributeKey NSCharacterEncodingDocumentAttribute API_AVAILABLE(macos(10.0), ios(7.0), tvos(9.0), watchos(2.0), visionos(1.0));  // @"CharacterEncoding", NSNumber containing integer specifying NSStringEncoding for the file; default for plain text is the default encoding.  This key in options can specify the string encoding for reading the data.  Upon return, the document attributes can contain the actual encoding used.  For writing methods, this value is used for generating the plain text data.
APPKIT_EXTERN NSAttributedStringDocumentAttributeKey NSDefaultAttributesDocumentAttribute API_AVAILABLE(macos(10.11), ios(6.0), tvos(9.0), watchos(2.0), visionos(1.0));  // @"DefaultAttributes", NSDictionary containing attributes to be applied to plain files.  Used by reader methods.  This key in options can specify the default attributes applied to the entire document contents.  The document attributes can contain this key indicating the actual attributes used.


// NSRTFTextDocumentType and NSRTFDTextDocumentType document attributes
// Document dimension
// They are document attributes used by read/write methods.
APPKIT_EXTERN NSAttributedStringDocumentAttributeKey NSPaperSizeDocumentAttribute API_AVAILABLE(macos(10.0), ios(7.0), tvos(9.0), watchos(2.0), visionos(1.0));  // @"PaperSize", NSValue containing CGSize (in points)

APPKIT_EXTERN NSAttributedStringDocumentAttributeKey NSViewSizeDocumentAttribute API_AVAILABLE(macos(10.0), ios(7.0), tvos(9.0), watchos(2.0), visionos(1.0));  // @"ViewSize", NSValue containing CGSize (in points)
APPKIT_EXTERN NSAttributedStringDocumentAttributeKey NSViewZoomDocumentAttribute API_AVAILABLE(macos(10.0), ios(7.0), tvos(9.0), watchos(2.0), visionos(1.0));  // @"ViewZoom", NSNumber containing floating point value (100 == 100% zoom)
APPKIT_EXTERN NSAttributedStringDocumentAttributeKey NSViewModeDocumentAttribute API_AVAILABLE(macos(10.0), ios(7.0), tvos(9.0), watchos(2.0), visionos(1.0));  // @"ViewMode", NSNumber containing integer; 0 = normal; 1 = page layout

// NSHTMLTextDocumentType document attributes
APPKIT_EXTERN NSAttributedStringDocumentAttributeKey const NSDefaultFontExcludedDocumentAttribute API_AVAILABLE(macos(14.0), ios(17.0), watchos(10.0), tvos(17.0), visionos(1.0)); // for HTML writing only; NSNumber containing a BOOL, when true the HTML writer will not include font information unless specified

// Document settings
// They are document attributes used by read/write methods.
APPKIT_EXTERN NSAttributedStringDocumentAttributeKey NSReadOnlyDocumentAttribute API_AVAILABLE(macos(10.0), ios(7.0), tvos(9.0), watchos(2.0), visionos(1.0));  // @"ReadOnly", NSNumber containing integer; if missing, or 0 or negative, not readonly; 1 or more, readonly. Note that this has nothing to do with the file system protection on the file, but instead, on how the file should be displayed to the user
APPKIT_EXTERN NSAttributedStringDocumentAttributeKey NSBackgroundColorDocumentAttribute API_AVAILABLE(macos(10.0), ios(7.0), tvos(9.0), watchos(2.0), visionos(1.0));  // @"BackgroundColor", UIColor, representing the document-wide page background color
APPKIT_EXTERN NSAttributedStringDocumentAttributeKey NSHyphenationFactorDocumentAttribute API_AVAILABLE(macos(10.0), ios(7.0), tvos(9.0), watchos(2.0), visionos(1.0));  // @"HyphenationFactor", NSNumber containing floating point value (0=off, 1=full hyphenation)
APPKIT_EXTERN NSAttributedStringDocumentAttributeKey NSDefaultTabIntervalDocumentAttribute API_AVAILABLE(macos(10.0), ios(7.0), tvos(9.0), watchos(2.0), visionos(1.0));  // @"DefaultTabInterval", NSNumber containing floating point value, representing the document-wide default tab stop interval, in points
APPKIT_EXTERN NSAttributedStringDocumentAttributeKey NSTextLayoutSectionsAttribute API_AVAILABLE(macos(10.7), ios(6.0), tvos(9.0), watchos(2.0), visionos(1.0));  // NSArray of dictionaries.  Each dictionary describing a layout orientation section.  The dictionary can have two attributes: NSTextLayoutSectionOrientation and NSTextLayoutSectionRange.  When there is a gap between sections, it's assumed to have NSTextLayoutOrientationHorizontal.

// Document text scaling and Cocoa version
// They are document attributes used by read/write methods.
APPKIT_EXTERN NSAttributedStringDocumentAttributeKey const NSTextScalingDocumentAttribute API_AVAILABLE(macos(10.15), ios(13.0), watchos(6.0), tvos(13.0), visionos(1.0));  // @"TextScaling", one of the text scaling types declared above. Only affects RTF documents.  For reading methods, this indicates the type of text scaling used in the returned attributed string.  For write methods, this attribute can be used in two different ways: (1) Passing only this attribute will overwrite the text scaling metadata in the document, but will not perform any conversion on the font sizes in the document, or (2) Passing both this attribute and NSSourceTextScalingDocumentAttribute will convert the font sizes in the document from the source text scaling type to the text scaling type specified by this attribute.

APPKIT_EXTERN NSAttributedStringDocumentAttributeKey const NSSourceTextScalingDocumentAttribute API_AVAILABLE(macos(10.15), ios(13.0), watchos(6.0), tvos(13.0), visionos(1.0));  // @"SourceTextScaling", one of the text scaling types declared above. Only affects RTF documents.  For writing methods, this indicates the type of text scaling in the attributed string that will be used as the base type for conversion.  Use this in conjunction with NSTextScalingDocumentAttribute to convert font point sizes between text scalings when writing attributed strings to RTF.  This attribute is optional and does nothing unless NSTextScalingDocumentAttribute is also specified.

APPKIT_EXTERN NSAttributedStringDocumentAttributeKey NSCocoaVersionDocumentAttribute API_AVAILABLE(macos(10.4), ios(13.0), watchos(6.0), tvos(13.0), visionos(1.0));  // @"CocoaRTFVersion", NSNumber containing integer.  Stores the version of Cocoa the file was created with.  NSNumber containing float.  Absence of this value indicates file not labelled as being created by Cocoa or its predecessors.  Values less than 100 are pre-Mac OS X; 100 is Mac OS X 10.0 and 10.1; 102 is Mac OS X 10.2 and 10.3; values greater than 102 correspond to values of NSAppKitVersionNumber on 10.4-10.14 systems.  Beginning with iOS 13 and macOS 10.15, this version number does not have a one-to-one correspondence with any single system framework version, but is guaranteed to monotonically increase with each OS version.

typedef NSString * NSAttributedStringDocumentReadingOptionKey NS_TYPED_EXTENSIBLE_ENUM API_AVAILABLE(macos(10.0), ios(6.0), tvos(9.0), watchos(2.0), visionos(1.0));

APPKIT_EXTERN NSAttributedStringDocumentReadingOptionKey NSDocumentTypeDocumentOption API_AVAILABLE(macos(10.0), ios(6.0), tvos(9.0), watchos(2.0), visionos(1.0));  // @"DocumentType", NSString indicating a document type to be forced when loading the document, specified as one of the NSDocumentTypeDocumentAttribute constants listed above
APPKIT_EXTERN NSAttributedStringDocumentReadingOptionKey NSDefaultAttributesDocumentOption API_AVAILABLE(macos(10.0), ios(6.0), tvos(9.0), watchos(2.0), visionos(1.0));  // @"DefaultAttributes", for plain text only; NSDictionary containing attributes to be applied to plain files
APPKIT_EXTERN NSAttributedStringDocumentReadingOptionKey NSCharacterEncodingDocumentOption API_AVAILABLE(macos(10.0), ios(6.0), tvos(9.0), watchos(2.0), visionos(1.0));  // @"CharacterEncoding", for plain text and HTML; NSNumber containing integer specifying NSStringEncoding to be used to interpret the file

APPKIT_EXTERN NSAttributedStringDocumentReadingOptionKey const NSTargetTextScalingDocumentOption API_AVAILABLE(macos(10.15), ios(13.0), watchos(6.0), tvos(13.0), visionos(1.0));  // @"TargetTextScaling", one of the text scaling types declared above.  Only affects RTF documents.  For reading methods, you can pass this option to request that the returned attributed string uses the specified scaling.  The font point sizes in the document may be converted if necessary.  If this option is not provided, the system will deduce the target text scaling type based on application framework and platform.

APPKIT_EXTERN NSAttributedStringDocumentReadingOptionKey const NSSourceTextScalingDocumentOption API_AVAILABLE(macos(10.15), ios(13.0), watchos(6.0), tvos(13.0), visionos(1.0));  // @"SourceTextScaling", one of the text scaling types declared above.  Only affects RTF documents.  For reading methods, you can pass this option to indicate the source text scaling type of the RTF document being read.  Use this in conjunction with NSTargetTextScalingDocumentOption to control text scaling conversions on the font point sizes in the returned attributed string.  This option does nothing unless NSTargetTextScalingDocumentOption is also specified.  If this option is not provided, the system will deduce the source text scaling type based on the information in the document.

// NSNumber containing a boolean value. When true, the TextKit1-style text list including the marker format string will be produced.
// NSAttributedString uses two representations for the text list. With TextKit2, the paragraph representing a text list item only contains the content. For example, " - text list A" is represented as "test list A" with a .hyphen NSTextList. TextKit1 requires the entire resolved text list content including the marker format string.
APPKIT_EXTERN NSAttributedStringDocumentReadingOptionKey const NSTextKit1ListMarkerFormatDocumentOption API_AVAILABLE(macos(15.0), ios(18.0), tvos(18.0), watchos(11.0), visionos(2.0));


@interface NSAttributedString (NSAttributedStringDocumentFormats)
// Methods initializing the receiver contents with an external document data.  options specify document attributes for interpreting the document contents.  NSDocumentTypeDocumentAttribute, NSCharacterEncodingDocumentAttribute, and NSDefaultAttributesDocumentAttribute are supported options key.  When they are not specified, these methods will examine the data and do their best to detect the appropriate attributes.  If dict is non-NULL, it will return a dictionary with various document-wide attributes accessible via NS...DocumentAttribute keys.
- (nullable instancetype)initWithURL:(NSURL *)url options:(NSDictionary<NSAttributedStringDocumentReadingOptionKey, id> *)options documentAttributes:(NSDictionary<NSAttributedStringDocumentAttributeKey, id> * __nullable * __nullable)dict error:(NSError **)error API_AVAILABLE(macos(10.4), ios(9.0), tvos(9.0), watchos(2.0), visionos(1.0));
- (nullable instancetype)initWithData:(NSData *)data options:(NSDictionary<NSAttributedStringDocumentReadingOptionKey, id> *)options documentAttributes:(NSDictionary<NSAttributedStringDocumentAttributeKey, id> * __nullable * __nullable)dict error:(NSError **)error API_AVAILABLE(macos(10.0), ios(7.0), tvos(9.0), watchos(2.0), visionos(1.0));

// Generates an NSData object for the receiver contents in range.  It requires a document attributes dict specifying at least the NSDocumentTypeDocumentAttribute to determine the format to be written.
- (nullable NSData *)dataFromRange:(NSRange)range documentAttributes:(NSDictionary<NSAttributedStringDocumentAttributeKey, id> *)dict error:(NSError **)error API_AVAILABLE(macos(10.0), ios(7.0), tvos(9.0), watchos(2.0), visionos(1.0));

// Returns an NSFileWrapper object for the receiver contents in range.  It requires a document attributes dict specifying at least the NSDocumentTypeDocumentAttribute to determine the format to be written.  The method returns a directory file wrapper for those document types represented by a file package such as NSRTFDTextDocumentType; otherwise, it returns a regular-file file wrapper.
- (nullable NSFileWrapper *)fileWrapperFromRange:(NSRange)range documentAttributes:(NSDictionary<NSAttributedStringDocumentAttributeKey, id> *)dict error:(NSError **)error API_AVAILABLE(macos(10.0), ios(7.0), tvos(9.0), watchos(2.0), visionos(1.0));

@end

@interface NSMutableAttributedString (NSMutableAttributedStringDocumentFormats)
// Methods replacing the receiver contents with an external document data.  options specify document attributes for interpreting the document contents.  NSDocumentTypeDocumentAttribute, NSCharacterEncodingDocumentAttribute, and NSDefaultAttributesDocumentAttribute are supported options key.  When they are not specified, these methods will examine the data and do their best to detect the appropriate attributes.  If dict is non-NULL, it will return a dictionary with various document-wide attributes accessible via NS...DocumentAttribute keys.
- (BOOL)readFromURL:(NSURL *)url options:(NSDictionary<NSAttributedStringDocumentReadingOptionKey, id> *)opts documentAttributes:(NSDictionary<NSAttributedStringDocumentAttributeKey, id> * __nullable * __nullable)dict error:(NSError **)error  API_AVAILABLE(macosx(10.5), ios(9.0), watchos(2.0), tvos(9.0));
- (BOOL)readFromData:(NSData *)data options:(NSDictionary<NSAttributedStringDocumentReadingOptionKey, id> *)opts documentAttributes:(NSDictionary<NSAttributedStringDocumentAttributeKey, id> * __nullable * __nullable)dict error:(NSError **)error API_AVAILABLE(macos(10.0), ios(7.0), tvos(9.0), watchos(2.0), visionos(1.0));
@end


/************************ Misc methods ************************/
@interface NSAttributedString (NSAttributedStringKitAdditions)
// Returns YES if the receiver contains a property configured (NSAttachmentAttributeName with NSAttachmentCharacter) in range
- (BOOL)containsAttachmentsInRange:(NSRange)range API_AVAILABLE(macos(10.11), ios(9.0), tvos(9.0), watchos(2.0), visionos(1.0));

// Returns YES when any attribute preferring RTFD found in range. This method should be preferred over containsAttachmentsInRange() for determining its preferred external document format.
- (BOOL)prefersRTFDInRange:(NSRange)range API_AVAILABLE(macos(15.0), ios(18.0), tvos(18.0), watchos(11.0), visionos(2.0));
@end

NS_HEADER_AUDIT_END(nullability, sendability)

#endif // !TARGET_OS_IPHONE
#else
#import <UIFoundation/NSAttributedString.h>
#endif

#import <Foundation/NSAttributedString.h>
#import <Foundation/NSItemProvider.h>
#import <AppKit/NSFontManager.h>
#import <AppKit/NSText.h>
#import <AppKit/NSPasteboard.h>
#import <AppKit/AppKitDefines.h>

@class NSTextBlock, NSTextTable, NSTextList;
@class NSFileWrapper;
@class NSURL;

#if !TARGET_OS_IPHONE
NS_HEADER_AUDIT_BEGIN(nullability, sendability)

APPKIT_EXTERN NSAttributedStringKey NSCursorAttributeName; // NSCursor, default IBeamCursor
APPKIT_EXTERN NSAttributedStringKey NSToolTipAttributeName; // NSString, default nil: no tooltip

APPKIT_EXTERN NSAttributedStringKey NSMarkedClauseSegmentAttributeName; // Clause segment index NSNumber (intValue). This attribute is used in marked text indicating clause segments

APPKIT_EXTERN NSAttributedStringKey NSTextAlternativesAttributeName API_AVAILABLE(macos(10.8)); // An NSTextAlternatives object.  Used primarily as a temporary attribute, with primaryString equal to the substring for the range to which it is attached, and alternativeStrings representing alternatives for that string that may be presented to the user.

APPKIT_EXTERN NSAttributedStringKey NSSpellingStateAttributeName;  // NSSpellingStateAttributeName is used and recognized only as a temporary attribute (see NSLayoutManager.h).  It indicates that spelling and/or grammar indicators should be shown for the specified characters, default 0: no spelling or grammar indicator


APPKIT_EXTERN NSAttributedStringKey NSSuperscriptAttributeName; // NSNumber containing integer, default 0
APPKIT_EXTERN NSAttributedStringKey NSGlyphInfoAttributeName;  // NSGlyphInfo specifying glyph for the associated attribute range

// Flag values supported for NSSpellingStateAttributeName as of Mac OS X version 10.5.  Prior to 10.5, any non-zero value caused the spelling indicator to be shown.
typedef NS_ENUM(NSInteger, NSSpellingState) {
    NSSpellingStateSpellingFlag API_AVAILABLE(macos(10.5)) = (1 << 0),
    NSSpellingStateGrammarFlag API_AVAILABLE(macos(10.5))  = (1 << 1)
};

/************************ Attribute fixing ************************/

@interface NSMutableAttributedString (NSAttributedStringAppKitAttributeFixing)
- (void)fixFontAttributeInRange:(NSRange)range;
- (void)fixParagraphStyleAttributeInRange:(NSRange)range;
- (void)fixAttachmentAttributeInRange:(NSRange)range;
@end

APPKIT_EXTERN NSAttributedStringDocumentType NSMacSimpleTextDocumentType;
APPKIT_EXTERN NSAttributedStringDocumentType NSDocFormatTextDocumentType;
APPKIT_EXTERN NSAttributedStringDocumentType NSWordMLTextDocumentType;
APPKIT_EXTERN NSAttributedStringDocumentType NSWebArchiveTextDocumentType;
APPKIT_EXTERN NSAttributedStringDocumentType NSOfficeOpenXMLTextDocumentType API_AVAILABLE(macos(10.5));
APPKIT_EXTERN NSAttributedStringDocumentType NSOpenDocumentTextDocumentType API_AVAILABLE(macos(10.5));

APPKIT_EXTERN NSAttributedStringDocumentAttributeKey NSConvertedDocumentAttribute;  // @"Converted", NSNumber containing integer; if missing, or 0, the file was originally in the format specified by document type; if negative, the file was originally in the format specified by document type, but the conversion to NSAttributedString may have been lossy; if 1 or more, it was converted to the specified type by a filter service
APPKIT_EXTERN NSAttributedStringDocumentAttributeKey NSFileTypeDocumentAttribute API_AVAILABLE(macos(10.6));  // NSString indicating which document type was used to interpret the document, specified as a UTI; for reading, this is available along with NSDocumentTypeDocumentAttribute, but for writing the two are mutually exclusive

APPKIT_EXTERN NSAttributedStringDocumentAttributeKey NSTitleDocumentAttribute;  // NSString containing document title
APPKIT_EXTERN NSAttributedStringDocumentAttributeKey NSCompanyDocumentAttribute;  // NSString containing company or organization name
APPKIT_EXTERN NSAttributedStringDocumentAttributeKey NSCopyrightDocumentAttribute;  // NSString containing document copyright info
APPKIT_EXTERN NSAttributedStringDocumentAttributeKey NSSubjectDocumentAttribute;  // NSString containing subject of document
APPKIT_EXTERN NSAttributedStringDocumentAttributeKey NSAuthorDocumentAttribute;  // NSString containing author name (not necessarily same as "last editor," see below)
APPKIT_EXTERN NSAttributedStringDocumentAttributeKey NSKeywordsDocumentAttribute;  // NSArray of NSString, containing keywords
APPKIT_EXTERN NSAttributedStringDocumentAttributeKey NSCommentDocumentAttribute;  // NSString containing document comments
APPKIT_EXTERN NSAttributedStringDocumentAttributeKey NSEditorDocumentAttribute;  // NSString containing name of person who last edited the document
APPKIT_EXTERN NSAttributedStringDocumentAttributeKey NSCreationTimeDocumentAttribute;  // NSDate containing the creation date of the document; note that this is not the file system creation date of the file, but of the document, as stored in the document
APPKIT_EXTERN NSAttributedStringDocumentAttributeKey NSModificationTimeDocumentAttribute;  // NSDate containing the modification date of the document contents
APPKIT_EXTERN NSAttributedStringDocumentAttributeKey NSManagerDocumentAttribute API_AVAILABLE(macos(10.5));  // NSString containing name of the author's manager
APPKIT_EXTERN NSAttributedStringDocumentAttributeKey NSCategoryDocumentAttribute API_AVAILABLE(macos(10.6));  // NSString containing the document category
APPKIT_EXTERN NSAttributedStringDocumentAttributeKey NSAppearanceDocumentAttribute API_AVAILABLE(macos(10.14)); // NSAppearance used to evaluate named NSColors when saving. The appearance itself is not written out; it is just used to determine the generated color component values. If not specified the canonical default light appearance is used.

// NSHTMLTextDocumentType document attributes
// Additional document attributes added in 10.4, for HTML writing only.  These provide control over the form of generated HTML.  NSExcludedElementsDocumentAttribute allows control over the tags used.  The recognized values in the NSExcludedElementsDocumentAttribute array are (case-insensitive) HTML tags, plus DOCTYPE (representing a doctype declaration) and XML (representing an XML declaration).  By default, if this attribute is not present, the excluded elements will be those deprecated in HTML 4 (APPLET, BASEFONT, CENTER, DIR, FONT, ISINDEX, MENU, S, STRIKE, and U) plus XML.  If XML is on the list, HTML forms will be used; if XML is not on the list, XHTML forms will be used where there is a distinction.  Either NSCharacterEncodingDocumentAttribute or NSTextEncodingNameDocumentAttribute may be used to control the encoding used for generated HTML; character entities will be used for characters not representable in the specified encoding.  Finally, NSPrefixSpacesDocumentAttribute allows some control over formatting.
APPKIT_EXTERN NSAttributedStringDocumentAttributeKey NSExcludedElementsDocumentAttribute;  // for HTML writing only; NSArray containing NSStrings, representing HTML elements not to be used in generated HTML
APPKIT_EXTERN NSAttributedStringDocumentAttributeKey NSTextEncodingNameDocumentAttribute;  // for HTML writing only; NSString containing the name, IANA or otherwise, of a text encoding to be used; mutually exclusive with NSCharacterEncodingDocumentAttribute
APPKIT_EXTERN NSAttributedStringDocumentAttributeKey NSPrefixSpacesDocumentAttribute;  // for HTML writing only; NSNumber containing integer, default 0, representing the number of spaces per level by which to indent certain nested HTML elements

APPKIT_EXTERN NSAttributedStringDocumentAttributeKey NSLeftMarginDocumentAttribute;  // @"LeftMargin", NSNumber containing floating point value (in points)
APPKIT_EXTERN NSAttributedStringDocumentAttributeKey NSRightMarginDocumentAttribute;  // @"RightMargin", NSNumber containing floating point value (in points)
APPKIT_EXTERN NSAttributedStringDocumentAttributeKey NSTopMarginDocumentAttribute;  // @"TopMargin", NSNumber containing floating point value (in points)
APPKIT_EXTERN NSAttributedStringDocumentAttributeKey NSBottomMarginDocumentAttribute;  // @"BottomMargin", NSNumber containing floating point value (in points)

APPKIT_EXTERN NSAttributedStringDocumentReadingOptionKey NSTextEncodingNameDocumentOption;  // @"TextEncodingName", for HTML only; NSString containing a name, IANA or otherwise, specifying an encoding to be used to interpret the file; mutually exclusive with NSCharacterEncodingDocumentOption
APPKIT_EXTERN NSAttributedStringDocumentReadingOptionKey NSBaseURLDocumentOption;  // @"BaseURL", for HTML only; NSURL containing a URL to be treated as the base URL for the document
APPKIT_EXTERN NSAttributedStringDocumentReadingOptionKey NSTimeoutDocumentOption;  // @"Timeout", for HTML only; NSNumber containing floating point value; time in seconds to wait for a document to finish loading; if not present or not positive, a default timeout will be used
APPKIT_EXTERN NSAttributedStringDocumentReadingOptionKey NSWebPreferencesDocumentOption;  // @"WebPreferences", for HTML only; WebPreferences; specifies a WebPreferences object describing a set of preferences; if not present, a default set of preferences will be used
APPKIT_EXTERN NSAttributedStringDocumentReadingOptionKey NSWebResourceLoadDelegateDocumentOption;  // @"WebResourceLoadDelegate", for HTML only; NSObject; specifies an object to serve as the WebResourceLoadDelegate; if not present, a default delegate will be used that will permit the loading of subsidiary resources but will not respond to authentication challenges
APPKIT_EXTERN NSAttributedStringDocumentReadingOptionKey NSTextSizeMultiplierDocumentOption;  // for HTML only; NSNumber containing floating point value, default 1.0; specifies a scale factor for font sizes, corresponding to WebView's textSizeMultiplier
APPKIT_EXTERN NSAttributedStringDocumentReadingOptionKey NSFileTypeDocumentOption API_AVAILABLE(macos(10.6));  // NSString indicating a document type to be forced when loading the document, specified as a UTI string; mutually exclusive with NSDocumentTypeDocumentOption

// In Mac OS X 10.4 and later, WebKit is always used for HTML documents, and all of the above options are recognized.  In Mac OS X 10.3, there is an additional options key, @"UseWebKit" (NSNumber containing integer; if present and positive, specifies that WebKit-based HTML importing is to be used).  In Mac OS X 10.3, the Timeout, WebPreferences, and WebResourceLoadDelegate options are recognized only when WebKit-based HTML importing is used.

@interface NSAttributedString (NSAttributedStringAppKitDocumentFormats)
- (nullable instancetype)initWithRTF:(NSData *)data documentAttributes:(NSDictionary<NSAttributedStringDocumentAttributeKey, id> * _Nullable * _Nullable)dict;
- (nullable instancetype)initWithRTFD:(NSData *)data documentAttributes:(NSDictionary<NSAttributedStringDocumentAttributeKey, id> * _Nullable * _Nullable)dict;
- (nullable instancetype)initWithHTML:(NSData *)data documentAttributes:(NSDictionary<NSAttributedStringDocumentAttributeKey, id> * _Nullable * _Nullable)dict;
- (nullable instancetype)initWithHTML:(NSData *)data baseURL:(NSURL *)base documentAttributes:(NSDictionary<NSAttributedStringDocumentAttributeKey, id> * _Nullable * _Nullable)dict;
- (nullable instancetype)initWithDocFormat:(NSData *)data documentAttributes:(NSDictionary<NSAttributedStringDocumentAttributeKey, id> * _Nullable * _Nullable)dict;
- (nullable instancetype)initWithHTML:(NSData *)data options:(NSDictionary<NSAttributedStringDocumentReadingOptionKey, id> *)options documentAttributes:(NSDictionary<NSAttributedStringDocumentAttributeKey, id> * _Nullable * _Nullable)dict;
- (nullable instancetype)initWithRTFDFileWrapper:(NSFileWrapper *)wrapper documentAttributes:(NSDictionary<NSAttributedStringDocumentAttributeKey, id> * _Nullable * _Nullable)dict;
- (nullable NSData *)RTFFromRange:(NSRange)range documentAttributes:(NSDictionary<NSAttributedStringDocumentAttributeKey, id> *)dict;
- (nullable NSData *)RTFDFromRange:(NSRange)range documentAttributes:(NSDictionary<NSAttributedStringDocumentAttributeKey, id> *)dict;
- (nullable NSFileWrapper *)RTFDFileWrapperFromRange:(NSRange)range documentAttributes:(NSDictionary<NSAttributedStringDocumentAttributeKey, id> *)dict;
- (nullable NSData *)docFormatFromRange:(NSRange)range documentAttributes:(NSDictionary<NSAttributedStringDocumentAttributeKey, id> *)dict;
@end

/************************ Misc methods ************************/
@interface NSAttributedString (NSAttributedStringAppKitAdditions)
// Attributes which should be copied/pasted with "copy font".
- (NSDictionary<NSAttributedStringKey, id> *)fontAttributesInRange:(NSRange)range;

// Attributes which should be copied/pasted with "copy ruler".
- (NSDictionary<NSAttributedStringKey, id> *)rulerAttributesInRange:(NSRange)range;

// Returns NSNotFound if no line break location found in the specified range; otherwise returns the index of the first character that should go on the NEXT line.
- (NSUInteger)lineBreakBeforeIndex:(NSUInteger)location withinRange:(NSRange)aRange;
- (NSUInteger)lineBreakByHyphenatingBeforeIndex:(NSUInteger)location withinRange:(NSRange)aRange;

- (NSRange)doubleClickAtIndex:(NSUInteger)location;
- (NSUInteger)nextWordFromIndex:(NSUInteger)location forward:(BOOL)isForward;


// Convenience methods for calculating the range of an individual text block, range of an entire table, range of a list, and the index within a list.
- (NSRange)rangeOfTextBlock:(NSTextBlock *)block atIndex:(NSUInteger)location;
- (NSRange)rangeOfTextTable:(NSTextTable *)table atIndex:(NSUInteger)location;
- (NSRange)rangeOfTextList:(NSTextList *)list atIndex:(NSUInteger)location;
- (NSInteger)itemNumberInTextList:(NSTextList *)list atIndex:(NSUInteger)location;
@end

@interface NSAttributedString (NSAttributedStringPasteboardAdditions)  <NSPasteboardReading, NSPasteboardWriting>
// Methods to determine what types can be loaded as NSAttributedStrings.
@property(class, readonly, copy) NSArray<NSString *> *textTypes API_AVAILABLE(macos(10.5));
@property(class, readonly, copy) NSArray<NSString *> *textUnfilteredTypes API_AVAILABLE(macos(10.5));
@end

@interface NSMutableAttributedString (NSMutableAttributedStringAppKitAdditions)
- (void)superscriptRange:(NSRange)range;
- (void)subscriptRange:(NSRange)range;
- (void)unscriptRange:(NSRange)range;
- (void)applyFontTraits:(NSFontTraitMask)traitMask range:(NSRange)range;
- (void)setAlignment:(NSTextAlignment)alignment range:(NSRange)range;
- (void)setBaseWritingDirection:(NSWritingDirection)writingDirection range:(NSRange)range;
@end

/************************ Deprecated ************************/
// NSUnderlineByWord and the NSUnderlinePattern* values are soft deprecated starting with macOS 10.14/iOS 12 and will be officially deprecated in a future release.  Please use the NSUnderlineStyle* equivalents instead.
// Underlines will be drawn with a solid pattern by default, so NSUnderlinePatternSolid does not need to be specified.
static const NSUnderlineStyle NSUnderlinePatternSolid = NSUnderlineStylePatternSolid;
static const NSUnderlineStyle NSUnderlinePatternDot = NSUnderlineStylePatternDot;
static const NSUnderlineStyle NSUnderlinePatternDash = NSUnderlineStylePatternDash;
static const NSUnderlineStyle NSUnderlinePatternDashDot = NSUnderlineStylePatternDashDot;
static const NSUnderlineStyle NSUnderlinePatternDashDotDot = NSUnderlineStylePatternDashDotDot;
static const NSUnderlineStyle NSUnderlineByWord = NSUnderlineStyleByWord;

APPKIT_EXTERN NSAttributedStringKey NSCharacterShapeAttributeName API_DEPRECATED("This attribute is bound to a specific implementation of ATS feature and not generically supported by wide range of fonts. The majority of characters accessed through this API are now encoded in the Unicode standard. Use the CTFont feature API for fine control over character shape choices.", macos(10.0,10.11));
APPKIT_EXTERN NSAttributedStringKey NSUsesScreenFontsDocumentAttribute API_DEPRECATED("", macos(10.8,10.11));

APPKIT_EXTERN NSAttributedStringKey  NSObliquenessAttributeName API_DEPRECATED("This attribute is not supported with TextKit 2", macos(10.0, API_TO_BE_DEPRECATED), ios(7.0, API_TO_BE_DEPRECATED), watchos(2.0, API_TO_BE_DEPRECATED), tvos(9.0, API_TO_BE_DEPRECATED));         // NSNumber containing floating point value; skew to be applied to glyphs, default 0: no skew
APPKIT_EXTERN NSAttributedStringKey  NSExpansionAttributeName API_DEPRECATED("This attribute is not supported with TextKit 2", macos(10.0, API_TO_BE_DEPRECATED), ios(7.0, API_TO_BE_DEPRECATED), watchos(2.0, API_TO_BE_DEPRECATED), tvos(9.0, API_TO_BE_DEPRECATED));           // NSNumber containing floating point value; log of expansion factor to be applied to glyphs, default 0: no expansion

APPKIT_EXTERN NSAttributedStringKey  NSVerticalGlyphFormAttributeName API_DEPRECATED("This attribute is not supported with TextKit 2", macos(10.7, API_TO_BE_DEPRECATED), ios(6.0, API_TO_BE_DEPRECATED), watchos(2.0, API_TO_BE_DEPRECATED), tvos(9.0, API_TO_BE_DEPRECATED));   // An NSNumber containing an integer value.  0 means horizontal text.  1 indicates vertical text.  If not specified, it could follow higher-level vertical orientation settings.  Currently on iOS, it's always horizontal.  The behavior for any other value is undefined.

enum {
    NSNoUnderlineStyle API_DEPRECATED("Use NSUnderlineStyleNone instead", macos(10.0,10.9)) = 0,
    NSSingleUnderlineStyle API_DEPRECATED("Use NSUnderlineStyleSingle instead", macos(10.0,10.9))
};

APPKIT_EXTERN NSUInteger NSUnderlineStrikethroughMask API_DEPRECATED("Use NSStrikethroughStyleAttributeName instead", macos(10.0,10.9));
APPKIT_EXTERN NSUInteger NSUnderlineByWordMask API_DEPRECATED("Use NSUnderlineByWord instead", macos(10.0,10.11));

@interface NSAttributedString(NSDeprecatedKitAdditions)
// This property is soft deprecated starting with OS X 10.11. It will be officially deprecated in a future release. Use -containsAttachmentsInRange: instead
@property (readonly) BOOL containsAttachments;

+ (NSArray *)textFileTypes API_DEPRECATED("", macos(10.1,10.5));
+ (NSArray *)textPasteboardTypes API_DEPRECATED("", macos(10.1,10.5));
+ (NSArray *)textUnfilteredFileTypes API_DEPRECATED("", macos(10.1,10.5));
+ (NSArray *)textUnfilteredPasteboardTypes API_DEPRECATED("", macos(10.1,10.5));

- (nullable instancetype)initWithURL:(NSURL *)url documentAttributes:(NSDictionary* _Nullable * _Nullable)dict API_DEPRECATED("Use -initWithURL:options:documentAttributes:error: instead", macos(10.0,10.11));
- (nullable instancetype)initWithPath:(NSString *)path documentAttributes:(NSDictionary* _Nullable * _Nullable)dict API_DEPRECATED("Use -initWithURL:options:documentAttributes:error: instead", macos(10.0,10.11));

- (nullable NSURL *)URLAtIndex:(NSUInteger)location effectiveRange:(NSRangePointer)effectiveRange API_DEPRECATED("Use NSDataDetector instead", macos(10.5,10.11));
@end

@interface NSMutableAttributedString (NSDeprecatedKitAdditions)
- (BOOL)readFromURL:(NSURL *)url options:(NSDictionary *)options documentAttributes:(NSDictionary* _Nullable * _Nullable)dict API_DEPRECATED("Use -readFromURL:options:documentAttributes:error: instead", macos(10.0,10.11));
- (BOOL)readFromData:(NSData *)data options:(NSDictionary *)options documentAttributes:(NSDictionary* _Nullable * _Nullable)dict API_DEPRECATED("Use -readFromData:options:documentAttributes:error: instead", macos(10.0,10.11));
@end
NS_HEADER_AUDIT_END(nullability, sendability)
#endif // !TARGET_OS_IPHONE
