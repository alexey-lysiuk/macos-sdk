/*
     NSWritingToolsCoordinatorContext.h
     Application Kit
     Copyright (c) 2024, Apple Inc.
     All rights reserved.
 */

#import <Foundation/NSObject.h>
#import <Foundation/NSRange.h>
#import <AppKit/AppKitDefines.h>

@class NSAttributedString;
@class NSUUID;

NS_HEADER_AUDIT_BEGIN(nullability, sendability)

/// A data object that you use to share your custom view’s text with Writing Tools.
///
/// At the start of every Writing Tools operation, you create one or more
/// `NSWritingToolsCoordinator.Context` objects with a copy of the text you want Writing Tools
/// to evaluate. Each Writing Tools operation starts with a call to the
/// ``NSWritingToolsCoordinator/Delegate/writingToolsCoordinator(_:requestsContextsFor:completion:)``
/// method of your ``NSWritingToolsCoordinator/Delegate`` object. Use the parameters
/// of that method to determine how much of your view’s text to provide. For
/// some operations, Writing Tools asks for all of your view’s text, but in
/// others it asks for only a portion of the text. When Writing Tools finishes
/// its evaluation, it reports changes back to your delegate relative to the
/// context objects you provided.
///
/// When Writing Tools asks for your view’s text, create one or more
/// `NSWritingToolsCoordinator.Context` objects with the requested content. If your view
/// contains only one text storage object, create only one context object for
/// the request. However, if you use multiple text storage objects to manage
/// different parts of your view’s content, you might need to create multiple
/// context objects. The actual number depends on how much of your text Writing
/// Tools asks for. For example, when Writing Tools asks for all of your view’s
/// content, you return one context object for each text storage object in your
/// view. However, if Writing Tools asks for the current selection, and one
/// text storage object contains all of the selected text, you create only
/// one context object for the content.
///
/// Writing Tools uses your context objects as the starting point for its
/// evaluations, and as a reference point for any changes. Because Writing
/// Tools doesn’t know anything about your view or its content, it makes
/// suggestions only relative to your context objects. It’s your responsibility
/// to take those suggestions and incorporate them back into your view’s
/// text storage. In some cases, you might need to store additional information
/// to update your storage correctly. For example, you might need to store,
/// and update as needed, the offset from the start of your document to the
/// start of the text in your context object.
///
/// When Writing Tools asks for the currently selected text in your view,
/// include some of the surrounding text in your context object as well.
/// Supply a string that includes the selection and any text up to the nearest
/// paragraph boundary. When creating your context object, specify a range
/// value that represents the portion of that string that corresponds to the
/// text selection. Providing some additional text in your context object can
/// help Writing Tools improve its evaluation of your content. Writing Tools
/// uses the ``resolvedRange`` property of your context object to indicate
/// what text it considered.
///
/// If your context object includes text that you don’t want Writing Tools to
/// evaluate, add the `excludeFromWritingTools` attribute to the corresponding
/// characters of your <doc://com.apple.documentation/documentation/foundation/nsattributedstring>
/// object. You might add this attribute if the text string includes a code
/// listing or readonly content that you don’t want Writing Tools to change.
API_AVAILABLE(macos(15.2)) NS_SWIFT_SENDABLE NS_SWIFT_NAME(NSWritingToolsCoordinator.Context)
@interface NSWritingToolsCoordinatorContext : NSObject

/// Creates a context object with the specified attributed string and range
/// information.
///
/// - Parameters:
///    - attributedString: A string that contains some or all of the content
///    from your view’s text storage. This initializer makes a copy of the
///    string you provide, so you can discard the original when you’re done.
///    - range: The portion of `attributedString` you want Writing Tools to
///    evaluate. If you want Writing Tools to evaluate the entire string you
///    provided, specify a range with a location of `0` and a length equal to
///    your string’s length. If you want Writing Tools to evaluate only part
///    of the string, provide the appropriate range in this parameter. Writing
///    Tools suggests changes only to the range of text you specify, but it
///    can consider text outside that range during the evaluation process.
///
/// When Writing Tools asks for your view’s current selection, it’s best to
/// create a string that includes text before and after that selection. During
/// the evaluation process, Writing Tools can use the additional text you
/// provided to improve the results it delivers. If you do provide additional
/// text, set the `range` parameter to the portion of `attributedString` with
/// the current selection. Don’t use the `range` parameter to specify the
/// location of the text in your view’s text storage.
- (instancetype)initWithAttributedString:(NSAttributedString *)attributedString range:(NSRange)range NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_UNAVAILABLE;

/// The portion of your view’s text to evaluate.
///
/// The ``NSWritingToolsCoordinator/Context`` object initializes the value of this
/// property at creation time and doesn’t change it during the course of an operation.
/// Instead, it suggests changes to the text in the indicated range and reports
/// those changes to your ``NSWritingToolsCoordinator/Delegate`` object. Use the methods
/// of your delegate object to integrate those changes back into your view’s text storage.
///
/// It’s your responsibility to track the location of this text in your
/// view’s text storage object. When Writing Tools reports changes,
/// it provides range values relative to this string. If you initialize
/// this property with a subset of your view’s content, you must adjust
/// any ranges that Writing Tools provides to get the correct location
/// in your text storage.
@property (copy, readonly) NSAttributedString *attributedString;

/// The unique identifier of the context object.
///
/// The ``NSWritingToolsCoordinator/Context`` object initializes the value of this property
/// at creation time. Use this value to identify the context object within your app.
@property (readonly) NSRange range; // The range it was initialized with

/// The unique identifier of the context object.
///
/// The ``NSWritingToolsCoordinator/Context`` object initializes the value of
/// this property at creation time. Use this value to identify the
/// context object within your app.
@property (strong, readonly) NSUUID *identifier;

/// The actual range of text that Writing Tools might change, which can
/// be different than the range of text you supplied.
///
/// After analyzing the text in your context object, Writing Tools sets
/// this property to the portion of ``attributedString`` it might modify.
/// Initially, this property has a location of
/// <doc://com.apple.documentation/documentation/foundation/nsnotfound> and a length
/// of `0`, but Writing Tools updates those values before making any changes
/// to the text.
///
/// While the Writing Tools operation is active, make sure Writing Tools has
/// exclusive access to the text in this range. Your ``NSWritingToolsCoordinator/Delegate``
/// object can make changes to the text as part of incorporating Writing Tools
/// results, but don’t allow changes to come from other sources. For example,
/// don’t let someone edit the text in this range directly until Writing Tools finishes.
@property (readonly) NSRange resolvedRange; // The range that Writing Tools ends up using (sometimes larger than range)
@end

NS_HEADER_AUDIT_END(nullability, sendability)
