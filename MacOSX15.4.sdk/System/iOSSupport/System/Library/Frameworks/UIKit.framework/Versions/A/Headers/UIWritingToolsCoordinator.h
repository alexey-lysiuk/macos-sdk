#if (defined(USE_UIKIT_PUBLIC_HEADERS) && USE_UIKIT_PUBLIC_HEADERS) || !__has_include(<UIKitCore/UIWritingToolsCoordinator.h>)
//
//  UIWritingToolsCoordinator.h
//  UIKit
//
//  Copyright © 2024 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIInteraction.h>
#import <UIKit/UITextInputTraits.h>

NS_HEADER_AUDIT_BEGIN(nullability, sendability)

@protocol UIWritingToolsCoordinatorDelegate;

/// Constants that specify the reason you updated your view’s content
/// outside of the Writing Tools workflow.
///
/// If you modify your view’s text storage while Writing Tools is active,
/// report those changes to your ``UIWritingToolsCoordinator`` object
/// so it can track them correctly. Call the
/// ``UIWritingToolsCoordinator/updateRange(_:with:reason:forContextWithIdentifier:)``
/// method to report changes that occur inside one of your context objects. Call the
/// ``UIWritingToolsCoordinator/updateForReflowedTextInContextWithIdentifier(_:)``
/// method for changes that affect the layout of your text, such as text insertions
/// before a context object or changes to your view’s frame rectangle.
typedef NS_ENUM(NSInteger, UIWritingToolsCoordinatorTextUpdateReason) {
    
    /// An operation that involved a person editing the text in your view.
    ///
    /// Specify this option when the changes come from the text input system.
    UIWritingToolsCoordinatorTextUpdateReasonTyping,
    
    /// An operation that changed the view’s text as part of an undo or
    /// redo command.
    ///
    /// Specify this option when an undo or redo command initiated the
    /// change to your view.
    UIWritingToolsCoordinatorTextUpdateReasonUndoRedo,
} API_AVAILABLE(ios(18.2), visionos(2.4)) API_UNAVAILABLE(tvos, watchos) NS_SWIFT_NAME(UIWritingToolsCoordinator.TextUpdateReason);

/// The states that indicate the current activity, if any, Writing Tools
/// is performing in your view.
///
/// Making changes to your view requires several different levels of
/// interaction. Initially, Writing Tools displays its UI and collects
/// information about what the person wants to do. When the person selects
/// an operation, Writing Tools sends the relevant details to a large language
/// model (LLM) and processes the results. It then works with the custom view to
/// integrate any changes into the view’s text storage. During each
/// of these activities, the coordinator reflects what’s happening in
/// its ``UIWritingToolsCoordinator/state`` property. You can use
/// the current state as a guide to making decisions in other parts of your view.
typedef NS_ENUM(NSInteger, UIWritingToolsCoordinatorState) {
    
    /// A state that indicates Writing Tools isn’t currently performing
    /// any work on your view’s content.
    ///
    /// The coordinator starts in the `inactive` state, and transitions
    /// immediately to the ``noninteractive`` or ``interactiveResting``
    /// state when someone chooses an option from the Writing Tools UI.
    /// After the coordinator finishes incorporating any changes for the
    /// current operation, it returns to the `inactive` state and waits
    /// for the person to choose a different option or dismiss the Writing Tools UI.
    UIWritingToolsCoordinatorStateInactive, // Writing Tools is not active
    
    /// A state that indicates Writing Tools is handling interactions in
    /// the system UI, instead of in your view.
    ///
    /// Writing Tools transitions to this state when the coordinator uses
    /// the ``UIWritingToolsBehavior/limited`` experience or when someone chooses an
    /// option that displays its results in the Writing Tools UI. When
    /// the person accepts the changes from the tool or dismisses the
    /// Writing Tools UI, the coordinator returns to the ``inactive``
    /// state. If the person discards the change and selects a tool with
    /// an interactive experience instead, the coordinator transitions
    /// to the ``interactiveResting`` state.
    UIWritingToolsCoordinatorStateNoninteractive, // Writing Tools is presenting UI, and the WTC may call the -writingToolsCoordinator:replaceRange:inContext:withText:reason: delegate method (with UIWritingToolsCoordinatorTextReplacementReasonNoninteractive) if the textual view is editable
    
    /// A state that indicates Writing Tools is in the resting state
    /// for an inline editing experience.
    ///
    /// When someone initially selects a tool with an interactive experience,
    /// the coordinator transitions briefly to this state and starts the
    /// operation. The coordinator transitions swiftly to the ``interactiveStreaming``
    /// state when it submits the request and delivers the results to your
    /// view. When it finishes delivering the results, it transitions back
    /// to the `interactiveResting` state and awaits further commands. If
    /// the person accepts the changes or dismisses the Writing Tools UI,
    /// the coordinator transitions from this state to the ``inactive`` state.
    UIWritingToolsCoordinatorStateInteractiveResting, // Writing Tools is providing the full inline-editing experience, and has delivered a complete set of results.
    
    /// A state that indicates Writing Tools is processing a request and
    /// incorporating changes interactively into your view.
    ///
    /// The coordinator transitions swiftly from the ``interactiveResting``
    /// state to this state at the start of an operation. In this state,
    /// the coordinator submits the request for processing and delivers
    /// the results back to your view. When the coordinator finishes delivering
    /// the results, it transitions back to the ``interactiveResting`` state.
    UIWritingToolsCoordinatorStateInteractiveStreaming, // Writing Tools is providing the full inline-editing experience, and is updating text, either because results are provided from AppleIntelligence, or because user interaction has requested changes, such as showing a different revision
} API_AVAILABLE(ios(18.2), visionos(2.4)) API_UNAVAILABLE(tvos, watchos) NS_SWIFT_NAME(UIWritingToolsCoordinator.State);


// MARK: - Coordinator
//

/// An object that manages interactions between Writing Tools and
/// your custom text view.
///
/// Add a `UIWritingToolsCoordinator` object to a custom view when you
/// want to add Writing Tools support to that view. The coordinator manages
/// interactions between your view and the Writing Tools UI and back-end
/// capabilities. When creating a coordinator, you supply a delegate object
/// to respond to requests from the system and provide needed information.
/// Your delegate delivers your view’s text to Writing Tools, incorporates
/// suggested changes back into your text storage, and supports the animations
/// that Writing Tools creates to show the state of an operation.
///
/// Create the `UIWritingToolsCoordinator` object when setting up your UI, and
/// initialize it with a custom object that adopts the ``UIWritingToolsCoordinator/Delegate``
/// protocol. Add the coordinator to your view using the ``UIView/addInteraction(_:)``
/// method. When a coordinator is present on a view, the system adds UI elements
/// to initiate Writing Tools operations.
///
/// When defining the delegate, choose an object from your app that has access
/// to your view and its text storage. You can adopt the ``UIWritingToolsCoordinator/Delegate``
/// protocol in the view itself, or in another type that your view uses to
/// manage content. During the interactions with Writing Tools, the delegate
/// gets and sets the contents of the view’s text storage and supports Writing Tools behaviors.
///
/// > Note: You don’t need to create an `UIWritingToolsCoordinator`  object
/// if you display text using a ``UITextView``,
/// <doc://com.apple.documentation/documentation/appkit/nstextview>,
/// <doc://com.apple.documentation/documentation/swiftui/text>,
/// <doc://com.apple.documentation/documentation/swiftui/textfield>, or
/// <doc://com.apple.documentation/documentation/swiftui/texteditor> view.
/// Those views already include the required support to handle Writing Tools
/// interactions.
UIKIT_EXTERN API_AVAILABLE(ios(18.2), visionos(2.4)) API_UNAVAILABLE(tvos, watchos) NS_SWIFT_UI_ACTOR
@interface UIWritingToolsCoordinator : NSObject <UIInteraction>

/// A Boolean value that indicates whether Writing Tools features are
/// currently available.
///
/// The value of this property is `true` when Writing Tools features are
/// available, and `false` when they aren’t. Writing Tools support might
/// be unavailable because of device constraints or because the system isn’t
/// ready to process Writing Tools requests.
@property (class, nonatomic, assign, readonly) BOOL isWritingToolsAvailable;

// The delegate must be non-nil when the UIWritingToolsCoordinator is added to a view.

/// Creates a writing tools coordinator and assigns the specified
/// delegate object to it.
///
/// - Parameters:
///    - delegate: An object capable of handling Writing Tools interactions
///    for your view. The delegate must be able to modify your view’s text
///    storage and refresh the view’s layout and appearance.
///
/// Create the coordinator object during your view’s initialization, and assign
/// the object to your view. Use the ``UIView/addInteraction(_:)``
/// method to add the object to your view.
- (instancetype)initWithDelegate:(nullable id <UIWritingToolsCoordinatorDelegate>)delegate;

/// The object that handles Writing Tools interactions for your view.
///
/// Specify this object at initialization time when creating your `UIWritingToolsCoordinator`
/// object. The object must adopt the ``UIWritingToolsCoordinator/Delegate``
/// protocol, and be capable of modifying your view’s text storage and
/// refreshing the view’s layout and appearance.
@property(nonatomic,weak,nullable,readonly) id<UIWritingToolsCoordinatorDelegate> delegate;

// Note: The effectContainerView and decorationContainerView may only be changed when UIWritingToolsCoordinator.State is .inactive, otherwise the setters will throw an exception.

/// The view that Writing Tools uses to display visual effects during
/// the text-rewriting process.
///
/// Writing Tools uses the view in this property to host the visual effects
/// it creates when making interactive changes to your view’s content.
/// These visual effects let people know the state of the text and provide
/// feedback about what’s happening to it. Set this property to a subview
/// that sits visually above, and covers, all of the text in your custom
/// text view. If you don’t assign a value to this property, the coordinator
/// uses the object in its ``UIInteraction/view`` property to host any visual effects.
///
/// If you display your view’s text using multiple text containers, implement the
/// ``UIWritingToolsCoordinator/Delegate/writingToolsCoordinator(_:requestsSingleContainerSubrangesOf:in:completion:)``
/// method to request multiple previews.
@property(nonatomic,weak,nullable) UIView *effectContainerView;

// The system draws underline and highlight decorations for proofreading suggestions in the decorationContainerView.

/// The view that Writing Tools uses to display background decorations
/// such as proofreading marks.
///
/// Writing Tools uses the view in this property to host proofreading marks
/// and other visual elements that show any suggested changes. Set this
/// property to a subview situated visibly below the text in your custom
/// text view. It's also satisfactory to place this view visually in front
/// of the text. Make sure the size of the view is big enough to
/// cover all of the affected text. If you don’t assign a value to
/// this property, the coordinator uses the object in its ``UIInteraction/view``
/// property to host any visual elements.
///
/// If you display your view’s text using multiple text containers, implement the
/// ``UIWritingToolsCoordinator/Delegate/writingToolsCoordinator(_:requestsSingleContainerSubrangesOf:in:completion:)``
/// and ``UIWritingToolsCoordinator/Delegate/writingToolsCoordinator(_:requestsDecorationContainerViewFor:in:completion:)``
/// methods to provide separate decoration views for each container.
@property(nonatomic,weak,nullable) UIView *decorationContainerView;

/// The current level of Writing Tools activity in your view.
///
/// Use this property to determine when Writing Tools is actively making
/// changes to your view. During the course of Writing Tools interactions,
/// the system reports state changes to the delegate’s
/// ``UIWritingToolsCoordinator/Delegate/writingToolsCoordinator(_:willChangeTo:completion:)``
/// method and updates this property accordingly.
@property(nonatomic,readonly) UIWritingToolsCoordinatorState state; // Values: Inactive, Noninteractive, InteractiveResting, InteractiveStreaming

// Clients may cancel Writing Tools if external events occur such that further input 
// from Writing Tools is not supportable, and then UIWritingToolsCoordinator will change 
// to the Inactive state.
// Also see UIResponder.showWritingTools().

/// Stops the current Writing Tools operation and dismisses the system UI.
///
/// Call this method to abort the current Writing Tools operation. This
/// method dismisses the system’s Writing Tools UI and stops any in-flight
/// interactions with your view. This method does not undo any changes that
/// Writing Tools already made to your view’s content.
- (void)stopWritingTools;

/// The level of Writing Tools support you want the system to provide
/// for your view.
///
/// Use this property to request an inline or panel-based experience,
/// or to disable Writing Tools for your view altogether. The default
/// value of this property is ``UIWritingToolsBehavior/default``.
@property(nonatomic) UIWritingToolsBehavior preferredBehavior; // Defaults to "Default"

/// The actual level of Writing Tools support the system provides for your view.
///
/// The system chooses this value based on the device capabilities, and takes
/// the value in the ``preferredBehavior`` property into consideration when
/// making the choice. The value in this property is never the default option,
/// and is instead one of the specific options such as ``UIWritingToolsBehavior/none``,
/// ``UIWritingToolsBehavior/limited``, or ``UIWritingToolsBehavior/complete``.
@property(nonatomic,readonly) UIWritingToolsBehavior behavior; // Returns None, Limited, or Complete after considering system information along with the value of preferredBehavior.

/// The type of content you allow Writing Tools to generate for your custom
/// text view.
///
/// Writing Tools can create plain text or rich text, and it can format text
/// using lists or tables as needed. If your view doesn’t support specific
/// types of content, specify the types you do support in this property.
/// The default value of this property is ``UIWritingToolsResultOptions/default``,
/// which lets the system determine the type of content to generate.
@property(nonatomic) UIWritingToolsResultOptions preferredResultOptions; // Defaults to "Default"

/// The type of content the system generates for your custom text view.
///
/// This property contains the set of options that Writing Tools outputs
/// for your view. Writing Tools takes the value in the
/// ``UIWritingToolsCoordinator/preferredResultOptions`` property into
/// consideration when determining this value.
@property(nonatomic,readonly) UIWritingToolsResultOptions resultOptions; // Returns a nonzero value after considering system information along with the value of preferredResultOptions

/// Informs the coordinator about changes your app made to the text
/// in the specified context object.
///
/// - Parameters:
///    - range: The range of text to replace. This range is relative to
///    the starting location of the specified context object’s text in
///    your view’s text storage. If you initialized the context object
///    with the entire contents of your view’s text storage, specify the
///    range of text you’re replacing in your text storage. However, if
///    you initialized the context object with only a portion of your
///    view’s text, specify a range that is relative to the starting
///    location of the context object’s text.
///    - replacementText: The text that replaces the previous content in
///    `range`. Specify an empty string to delete the text in the specified range.
///    - reason: The reason you updated the text.
///    - contextID: The unique identifier of the context object that
///    contains the text you modified.
///
/// If you make any changes to the text Writing Tools is evaluating, call
/// this method to report those changes to your view’s coordinator object.
/// You might make changes in response to an undo command or when someone
/// types into the same part of your view’s text. Calling this method
/// keeps the coordinator object informed of any changes, and ensures
/// it delivers accurate information to its delegate. In response, the
/// coordinator refreshes previews and other information related to your
/// view. If the scope of the update is significantly large, the coordinator
/// can optionally cancel the Writing Tools session altogether.
///
/// Use this method to report changes that precisely intersect your context
/// object’s text. The first time you call this method for a context object,
/// report changes only to the original attributed string in that object.
/// If you call this method more than once, report changes to the newly
/// modified version of that string. Don’t use this method to report changes
/// to text that comes before or after the context object. If you make
/// changes before your context object, report those changes separately using the
/// ``UIWritingToolsCoordinator/updateForReflowedTextInContextWithIdentifier(_:)`` method.
///
/// > Warning: Failure to call this method for a change can cause Writing Tools
/// to deliver inaccurate information to your delegate and lead to data loss.
- (void)updateRange:(NSRange)range withText:(NSAttributedString *)replacementText reason:(UIWritingToolsCoordinatorTextUpdateReason)reason forContextWithIdentifier:(NSUUID *)contextID NS_SWIFT_NAME(updateRange(_:with:reason:forContextWithIdentifier:));

/// Informs the coordinator that a change occurred to the view or its text
/// that requires a layout update.
///
/// - Parameters:
///    - contextID: The unique identifier of the context object affected
///    by the change. Pass the identifier for the context object that comes
///    after the changes.
///
/// Use this method to inform Writing Tools when the geometry of your view
/// changes, or when the text that precedes one of your context objects changes.
/// Changes to the view’s geometry or text can affect the flow of any remaining
/// text, and require a layout update. Writing Tools uses this method to
/// refresh any layout-dependent information it’s currently tracking. For
/// example, it uses it to refresh the location of proofreading marks it’s
/// displaying in your view.
///
/// If a text change affects the text inside a context object, call the
/// ``updateRange(_:with:reason:forContextWithIdentifier:)`` method to report
/// that change instead.
- (void)updateForReflowedTextInContextWithIdentifier:(NSUUID *)contextID NS_SWIFT_NAME(updateForReflowedTextInContextWithIdentifier(_:));
@end

// MARK: - Delegate
//
#if !TARGET_OS_WATCH
@class UITargetedPreview;
#endif
@class UIWritingToolsCoordinatorContext, UIWritingToolsCoordinatorAnimationParameters, UIBezierPath, UIView;

/// Options that indicate whether Writing Tools is animating changes to
/// your view’s text.
///
/// During an operation, Writing Tools delivers replacement text to the
/// delegate of the active ``UIWritingToolsCoordinator`` object. Depending
/// on the configured experience for your view, it delivers these changes
/// as either interactive or noninteractive replacements. For interactive
/// replacements, Writing Tools animates the change automatically and provides
/// you with the information you need to perform any related animations.
typedef NS_ENUM(NSInteger, UIWritingToolsCoordinatorTextReplacementReason) {
    
    /// An option to animate the replacement of text in your view.
    ///
    /// When Writing Tools requests an interactive change in your delegate’s
    /// ``UIWritingToolsCoordinator/Delegate/writingToolsCoordinator(_:replaceRange:inContext:proposedText:reason:animationParameters:completion:)``
    /// method, it passes a valid set of animation parameters to that method.
    /// Update your view’s text storage and use the provided ``UIWritingToolsCoordinator/AnimationParameters``
    /// type to create any view-specific animations you need to support the
    /// animated replacement of the text.
    UIWritingToolsCoordinatorTextReplacementReasonInteractive, // animating a chunk from a proofreading or rewrite inline delivery
    
    /// An option to replace the text in your view without animating the change.
    ///
    /// When Writing Tools requests a noninteractive change in your delegate’s
    /// ``UIWritingToolsCoordinator/Delegate/writingToolsCoordinator(_:replaceRange:inContext:proposedText:reason:animationParameters:completion:)``
    /// method, update your view’s text storage without animating the change.
    UIWritingToolsCoordinatorTextReplacementReasonNoninteractive, // an unanimated replacement prompted from writing tools, perhaps copied from the overlay-panel experience, perhaps a reverted rewrite or individual proofreading suggestion, and so forth
} API_AVAILABLE(ios(18.2), visionos(2.4)) API_UNAVAILABLE(tvos, watchos) NS_SWIFT_NAME(UIWritingToolsCoordinator.TextReplacementReason);

/// Options that indicate how much of your content Writing Tools requested.
///
/// At the start of any Writing Tools interaction, you provide the text for
/// the system to evaluate from your ``UIWritingToolsCoordinator/Delegate``
/// object. The request for your content comes with a scope constant that
/// indicates how much of your view’s text to provide.
typedef NS_ENUM(NSInteger, UIWritingToolsCoordinatorContextScope) {
    
    /// An option to provide only the view’s currently selected text.
    ///
    /// With this option, include the selected text in your context object,
    /// along with some additional text before and after the selection. When
    /// performing changes inline with your view’s content, Writing Tools
    /// applies animations only to the selected text.
    UIWritingToolsCoordinatorContextScopeUserSelection, // For best results return a context where attributedString is at least a full paragraph and range is the selected range within that attributedText.
    
    /// An option to provide all of your view’s text.
    ///
    /// With this option, include all of the text your view manages.
    /// If your view has multiple text storage objects, create a separate
    /// context object for each one.
    UIWritingToolsCoordinatorContextScopeFullDocument, // For best results return a context where attributedString is the full text from the text storage.
    
    /// An option to provide only the text in the currently visible portion
    /// of your view.
    ///
    /// With this option, include only the currently visible text, along
    /// with some additional text before and after the visible text.
    UIWritingToolsCoordinatorContextScopeVisibleArea, // For best results return a context where attributedString includes all visible text.
    
} API_AVAILABLE(ios(18.2), visionos(2.4)) API_UNAVAILABLE(tvos, watchos) NS_SWIFT_NAME(UIWritingToolsCoordinator.ContextScope);

/// The types of animations that Writing Tools performs during an interactive
/// update of your view.
///
/// Use the `UIWritingToolsCoordinator/TextAnimation` constants to determine
/// the type of animation that is occurring. During an interactive change to
/// your view, Writing Tools creates animations to provide feedback about what’s
/// happening. During the setup for each animation, Writing Tools reports the
/// type of animation to the coordinator’s delegate, so that you can perform
/// additional actions related to that animation. For example, during an insertion
/// animation, you might animate changes to other views in your interface.
typedef NS_ENUM(NSInteger, UIWritingToolsCoordinatorTextAnimation) {
    
    /// The animation that Writing Tools performs when waiting to receive
    /// results from the large language model.
    ///
    /// This type of animation applies a visual effect to the text that
    /// Writing Tools is evaluating. When preparing for this animation, hide
    /// the text that Writing Tools is about to evaluate. In the same space
    /// where that text appears, Writing Tools displays a preview image that
    /// you provide and animates changes to that image.
    UIWritingToolsCoordinatorTextAnimationAnticipate, // The animation effect for the text awaiting the results of the Writing Tools evaluation
    
    /// The animation that Writing Tools performs when removing text from your view.
    ///
    /// This type of animation shows the removal of text from your view. When
    /// preparing for this animation, hide the text in the provided range if
    /// you haven’t already. If you support animating the reflow of your view’s
    /// text, you can also prepare any other animations you need. Writing Tools
    /// uses a preview object you provide to animate the removal of the text.
    UIWritingToolsCoordinatorTextAnimationRemove, // The animation effect for washing out text that will be replaced by a Writing Tools delivery
    
    /// The animation that Writing Tools performs when inserting text into your view.
    ///
    /// This type of animation shows the insertion of text to your view. When preparing
    /// for this animation, hide the text in the provided range if you haven’t
    /// already. If you support animating the reflow of your view’s text, you can
    /// also prepare any other animations you need. Writing Tools uses a preview
    /// object you provide to animate the insertion of the text.
    UIWritingToolsCoordinatorTextAnimationInsert, // The amimation effect for washing in replacement text from a Writing Tools delivery
} API_AVAILABLE(ios(18.2), visionos(2.4)) API_UNAVAILABLE(tvos, watchos) NS_SWIFT_NAME(UIWritingToolsCoordinator.TextAnimation);

UIKIT_EXTERN 
API_AVAILABLE(ios(18.2), visionos(2.4)) API_UNAVAILABLE(tvos, watchos)
NSString *UIWritingToolsCoordinatorTextAnimationDebugDescription(UIWritingToolsCoordinatorTextAnimation animationType);

/// An interface that you use to manage interactions between Writing Tools
/// and your custom text view.
///
/// Adopt the `UIWritingToolsCoordinator.Delegate` protocol in the type you
/// use to manage your custom text view. When you add a ``UIWritingToolsCoordinator``
/// object to your view, the coordinator uses this protocol to communicate
/// with that view. The protocol lets Writing Tools fetch your view’s text,
/// report suggested changes back to your view, and deliver visual feedback
/// when Writing Tools features are active. Make sure the type that adopts
/// this protocol has access to your view’s text storage and can perform
/// relevant tasks on behalf of the view.
///
/// Writing Tools expects you to call the provided handler blocks at the end
/// of your delegate methods. It’s crucial that you execute these blocks in a
/// timely manner to allow Writing Tools to perform subsequent tasks. For example,
/// Writing Tools waits for you to execute the handlers for animation-related methods
/// before moving on to the next stage of the animations.
API_AVAILABLE(ios(18.2), visionos(2.4)) API_UNAVAILABLE(tvos, watchos)
NS_SWIFT_NAME(UIWritingToolsCoordinator.Delegate)
@protocol UIWritingToolsCoordinatorDelegate <NSObject>

/// Asks your delegate to provide the text to evaluate during the Writing Tools
/// operation.
///
/// - Parameters:
///    - writingToolsCoordinator: The coordinator object requesting information
///    from your custom view.
///    - scope: The amount of text the coordinator requested. Use this property
///    to determine if Writing Tools is evaluating all of your text or only a subset.
///    - completion: A completion block to execute with the required information.
///    You must execute this block once at end of your method's implementation.
///    The block has no return value and takes an array of
///    ``UIWritingToolsCoordinator/Context`` objects that contain the requested information.
///
/// At the start of every operation, the ``UIWritingToolsCoordinator`` object calls
/// this method to request the text to evaluate. Use this method to create one or
/// more ``UIWritingToolsCoordinator/Context`` objects with your view’s text.
/// Create only one ``UIWritingToolsCoordinator/Context`` object if your view has
/// only one text storage object. If your view contains multiple text storage objects,
/// create separate ``UIWritingToolsCoordinator/Context`` objects for each
/// text storage object. Writing Tools returns updates for each context object
/// separately, making it easier for you to incorporate changes into the correct
/// text storage object. Don’t create multiple context objects if your view has
/// only one text storage object.
///
/// The `scope` parameter tells you what content Writing Tools expects you to provide
/// in your context object. For example, Writing Tools expects you to provide the
/// selected text when the parameter contains the ``UIWritingToolsCoordinator/ContextScope/userSelection``
/// option. When Writing Tools requests a subset of your overall text, include
/// some of the surrounding text in your context object too. Writing Tools can
/// use the extra text you provide to improve the results of its evaluation. For
/// example, it might use an entire paragraph, instead of only the selected sentence,
/// to evaluate ways to rewrite that sentence. It’s best to include the text up
/// to the nearest paragraph boundary before and after the selection. If you
/// include extra text in your context object, set the ``UIWritingToolsCoordinator/Context/range``
/// property to the range of the selected text.
///
/// > Note: When a context object stores only a subset of your view’s text, record
/// additional information to map the location of that text to the correct location
/// in your view’s text storage. Keep that information up-to-date throughout the
///  Writing Tools session.
///
/// Pass the context objects you create to the provided completion handler before
/// your method returns. Writing Tools waits for you to call the completion
/// handler before proceeding with the operation.
- (void)writingToolsCoordinator:(UIWritingToolsCoordinator *)writingToolsCoordinator requestsContextsForScope:(UIWritingToolsCoordinatorContextScope)scope completion:(void(^)(NSArray<UIWritingToolsCoordinatorContext *> *))completion NS_SWIFT_ASYNC_NAME(writingToolsCoordinator(_:contextsFor:));

/// Tells the delegate that there are text changes to incorporate into the view.
///
/// - Parameters:
///    - writingToolsCoordinator: The coordinator object providing the changes
///    to your custom view.
///    - range: A range of text to update. This range is relative to the text
///    in your context object, and it’s your responsibility to match that location
///    to the correct location in your text storage. If you initialized the
///    context object with the entire contents of your view’s text storage,
///    you can use `range` as-is to access that text storage. However, if you
///    initialized the context object with only a portion of your view’s text,
///    add the starting location of your context object’s text to this value
///    to get the correct range for that text storage.
///    - context: The context object that contains the original text to modify.
///    Use this object to locate the correct text storage object for your view.
///    - replacementText: The text to insert in place of the current text at `range`.
///    You can insert this text as-is, insert a modified version of this string,
///    or reject the replacement text altogether.
///    - reason: The type of replacement Writing Tools performs. This parameter
///    indicates whether Writing Tools is replacing the text with or without animations.
///    - animationParameters: The animation parameters for any interactive changes,
///    or `nil` if the changes aren’t interactive. Use this object to create any
///    additional animations for the system to run alongside the changes Writing Tools
///    makes. For example, use it to update other views that contain related information.
///    - completion: A completion handler to execute with the results of the operation.
///    The handler has no return value and takes an optional attributed string as
///    a parameter. If you incorporate the replacement text, either as-is or with
///    modifications, pass the actual string you incorporated to the completion
///    block. If you reject the suggested change and leave the original text
///    unchanged, specify `nil` for this parameter.
///
/// Use this method to update your view’s text storage with the proposed changes.
/// Writing Tools can call this method multiple times during the course of a
/// session to notify you of changes to different ranges of text. Incorporate
/// the changes into your view’s text storage and notify your layout manager
/// so it can refresh the view.
///
/// > Important: When integrating changes, remember to update `range.location` as needed
/// to get the correct location in your view’s text storage.
///
/// Remove the text in the appropriate range of your text storage, and replace
/// it with the contents of `replacementText`. When you finish, call the completion
/// handler and pass in the replacement text you inserted. If you change the
/// string in `replacementText` before incorporating it into your text storage,
/// return your modified string instead. Returning the string lets Writing Tools
/// track any alterations you made to it. You can also pass `nil` to the
/// completion handler if you don’t incorporate the replacement text.
///
/// For interactive changes, Writing Tools works with your delegate to animate
/// the removal of the old text and the insertion of any replacement text. If
/// you need to modify other parts of your interface to reflect the changes,
/// use the provided ``UIWritingToolsCoordinator/AnimationParameters`` object
/// to create additional animations to run at the same time as the system-provided animations.
- (void)writingToolsCoordinator:(UIWritingToolsCoordinator *)writingToolsCoordinator replaceRange:(NSRange)range inContext:(UIWritingToolsCoordinatorContext *)context proposedText:(NSAttributedString *)replacementText reason:(UIWritingToolsCoordinatorTextReplacementReason)reason  animationParameters:(UIWritingToolsCoordinatorAnimationParameters *__nullable)animationParameters completion:(void(^)(NSAttributedString *__nullable))completion;

/// Asks the delegate to update your view’s current text selection.
///
/// - Parameters:
///    - writingToolsCoordinator: The coordinator object making the change
///    to your view.
///    - ranges: One or more ranges of text to select. Each range is relative
///    to the text in your context object, and it’s your responsibility to
///    match each location to the correct location in your text storage. If
///    you initialized the context object with the entire contents of your
///    view’s text storage, you can use the ranges as-is to access that text
///    storage. However, if you initialized the context object with only a
///    portion of your view’s text, add the starting location of your context
///    object’s text to each value to get the correct range for that text storage.
///    - context: The context object you use to identify the associated text storage.
///    - completion: The completion handler to execute when your delegate finishes updating
///    the selection. The handler has no parameters or return value. You must
///    call this handler at some point during the implementation of your method.
///
/// As Writing Tools suggests changes to your view’s text, it calls this method
/// to update the text selection accordingly. Use this method to update the
/// current selection in your view’s text storage. When you finish making the
/// changes, call the provided completion block to let Writing Tools know you’re finished.
- (void)writingToolsCoordinator:(UIWritingToolsCoordinator *)writingToolsCoordinator selectRanges:(NSArray<NSValue * /* NSRange */> *)ranges inContext:(UIWritingToolsCoordinatorContext *)context completion:(void(^)(void))completion NS_SWIFT_NAME(writingToolsCoordinator(_:select:in:completion:));

/// Asks the delegate to provide the bounding paths for the specified
/// text in your view.
///
/// - Parameters:
///     - writingToolsCoordinator: The coordinator object requesting information
///     from your custom view.
///     - range: The range of text to evaluate. This range is relative to the
///     text in your context object, and it’s your responsibility to match that
///     location to the correct location in your text storage. If you initialized
///     the context object with the entire contents of your view’s text storage,
///     you can use `range` as-is to access that text storage. However, if you
///     initialized the context object with only a portion of your view’s text,
///     add the starting location of your context object’s text to this value to
///     get the correct range for that text storage.
///     - context: The context object with the target text. Use this object to
///     find the text in your view’s text storage.
///     - completion: A handler to execute with the required information. The
///     handler has no return value and takes an array of Bezier paths as a
///     parameter. You must call this handler at some point during your method’s implementation.
///
/// After applying proofreading marks to your view’s text, Writing Tools lets
/// the person accept or reject individual suggestions. To facilitate interactions,
/// the coordinator asks your delegate to provide one or more Bezier paths that
/// surround those proofreading suggestions. For each distinct range of text
/// with a suggestion, it calls this method to get the Bezier paths that surround
/// the corresponding text.
///
/// After you determine the location of the specified range of text in your view’s
/// text storage, call the <doc://com.apple.documentation/documentation/uikit/nstextlayoutmanager/3809995-enumeratetextsegments>
/// method of your view’s <doc://com.apple.documentation/documentation/uikit/nstextlayoutmanager>
/// to compute the selection rectangles for that text. That method finds the text
/// segments that contain the text and returns the frame rectangle for each one.
/// Create a Bezier path for each rectangle, and convert the coordinates of each path
/// to the coordinate space of the view in your coordinator's ``UIWritingToolsCoordinator/decorationContainerView``
/// property. Pass the resulting paths to the completion handler.
- (void)writingToolsCoordinator:(UIWritingToolsCoordinator *)writingToolsCoordinator requestsBoundingBezierPathsForRange:(NSRange)range inContext:(UIWritingToolsCoordinatorContext *)context completion:(void(^)(NSArray<UIBezierPath *> *))completion NS_SWIFT_ASYNC_NAME(writingToolsCoordinator(_:boundingBezierPathsFor:context:));

/// Asks the delegate to provide an underline shape for the specified text
/// during a proofreading session.
///
/// - Parameters:
///     - writingToolsCoordinator: The coordinator object requesting information
///     from your custom view.
///     - range: The range of text to evaluate. This range is relative to the
///     text in your context object, and it’s your responsibility to match that
///     location to the correct location in your text storage. If you initialized
///     the context object with the entire contents of your view’s text storage,
///     you can use `range` as-is to access that text storage. However, if you
///     initialized the context object with only a portion of your view’s text,
///     add the starting location of your context object’s text to this value
///     to get the correct range for that text storage.
///     - context: The context object with the target text. Use this object to
///     find the text in your view’s text storage.
///     - completion: A handler to execute with the required information. The
///     handler has no return value and takes an array of Bezier paths as a
///     parameter. You must call this handler at some point during your method’s implementation.
///
/// When applying proofreading marks to your view’s content, the coordinator
/// calls this method to retrieve a shape to draw under the specified text.
/// You provide the shape using one or more Bezier paths, and the coordinator
/// draws and animates that shape during the proofreading session.
///
/// After you determine the location of the specified range of text in your
/// view’s text storage, find the rectangle around that text. If you're using
/// TextKit, you can call the <doc://com.apple.documentation/documentation/uikit/nstextlayoutmanager/3809995-enumeratetextsegments>
/// method of your view’s <doc://com.apple.documentation/documentation/uikit/nstextlayoutmanager>
/// to get the rectangles for a range of text. Convert the coordinates of each rectangle
/// to the coordinate space of the view in your coordinator's ``UIWritingToolsCoordinator/decorationContainerView``
/// property. Use those rectangles to create the Bezier paths for your text.
/// For example, you might create a path with a straight or wavy line at the
/// bottom of the rectangle.
- (void)writingToolsCoordinator:(UIWritingToolsCoordinator *)writingToolsCoordinator requestsUnderlinePathsForRange:(NSRange)range inContext:(UIWritingToolsCoordinatorContext *)context completion:(void(^)(NSArray<UIBezierPath *> *))completion NS_SWIFT_ASYNC_NAME(writingToolsCoordinator(_:underlinePathsFor:context:));

//
// Animation support
//
// range.location is an offset from the beginning of the resolvedRange throughout. Expected to match textual view's text storage, presuming client has been updating as expected through the text delegate replaceRange

// The client is expected to hide the range of text, and if supporting animating reflow of following text for UIWritingToolsCoordinatorTextAnimationInsert and UIWritingToolsCoordinatorTextAnimationRemove, do any setup necessary.

/// Prepare for animations for the content that Writing Tools is evaluating.
///
/// - Parameters:
///    - writingToolsCoordinator: The coordinator object notifying you that
///    animations are about to begin.
///    - textAnimation: The type of animation Writing Tools is preparing.
///    - range: The range of text affected by the animation. This range is
///    relative to the text in your context object, and it’s your responsibility
///    to match that location to the correct location in your text storage.
///    If you initialized the context object with the entire contents of your
///    view’s text storage, you can use `range` as-is to access that text
///    storage. However, if you initialized the context object with only a portion
///    of your view’s text, add the starting location of your context object’s
///    text to this value to get the correct range for that text storage.
///    - context: The context object that contains the original text. Use this
///    object to fetch the current text, and to match that text to your underlying
///    text storage.
///    - completion: A completion handler to execute when you are done. The handler
///    has no return value and takes no parameters. You must call this handler
///    at some point during your implementation.
///
/// During an interactive evaluation of your view’s text, Writing Tools creates
/// different animations to provide feedback on what’s happening. For example, it
/// creates an ``UIWritingToolsCoordinator/TextAnimation/anticipate`` animation to
/// let people know the system is evaluating the text. The `textAnimation` parameter
/// tells you what type of animation to prepare for.
///
/// Use this method to prepare for the system-provided animations of your view’s
/// content. For interactive animations, hide the text in the specified range temporarily
/// while the system animations run. For non-interactive animations, dim the text
/// for the duration of the animation to indicate it’s not editable. For animations
/// to remove or insert text, you can also use this method to set up animations
/// to reflow your view’s content to match the changes. At the end of a given animation,
/// use your delegate’s ``writingToolsCoordinator(_:finish:for:in:completion:)``
/// method to undo any changes you make to your content.
///
/// For a single animation type, the system calls the
/// ``writingToolsCoordinator(_:requestsPreviewFor:range:context:completion:)`` method,
/// followed sequentially by this method and the ``writingToolsCoordinator(_:finish:for:in:completion:)``
/// method. Each method executes asynchronously, but the system calls the next
/// method in the sequence only after you call the completion handler of the previous
/// method. However, multiple animations can run simultaneously, so check the
/// `textAnimation` and `range` parameters to differentiate sequences.
- (void)writingToolsCoordinator:(UIWritingToolsCoordinator *)writingToolsCoordinator prepareForTextAnimation:(UIWritingToolsCoordinatorTextAnimation)textAnimation forRange:(NSRange)range inContext:(UIWritingToolsCoordinatorContext *)context completion:(void(^)(void))completion;


#if TARGET_OS_WATCH // {
/// Asks the delegate for a preview image and layout information for the
/// specified text.
///
/// - Parameters:
///    - writingToolsCoordinator: The coordinator object notifying you that
///    animations are about to begin.
///    - textAnimation: The type of animation Writing Tools is preparing.
///    - range: The range of text that requires a preview image. This range
///    is relative to the text in your context object, and it’s your responsibility
///    to match that location to the correct location in your text storage.
///    If you initialized the context object with the entire contents of
///    your view’s text storage, you can use `range` as-is to access that
///    text storage. However, if you initialized the context object with only
///    a portion of your view’s text, add the starting location of your
///    context object’s text to this value to get the correct range for that
///    text storage.
///    - context: The context object that contains the original text. Use this
///    object to fetch the current text, and to match that text to your
///    underlying text storage.
///    - completion: A completion handler to execute when you are done. The
///    handler has no return value and takes a ``UITargetedPreview`` object
///    as a parameter. You must call this handler at some point during your implementation.
///
/// During an interactive evaluation of your view’s text, Writing Tools creates
/// different animations to provide feedback on what’s happening. As part of
/// the preparation for those animations, Writing Tools asks you to provide
/// a preview of the affected content in your view. Writing Tools uses this
/// preview to build and execute the animations in the view stored in the
/// ``UIWritingToolsCoordinator/effectContainerView`` property of the coordinator object.
///
/// To build a preview of your content in iOS, render the specified range of
/// text into an image with a transparent background. Install the image in a
/// ``UIImageView`` and use that to build your preview object. Set the frame
/// rectangle of your image view to the rectangle in your view’s coordinate
/// space that contains the text you captured. When creating the ``UITargetedPreview``
/// object, include both a ``UIPreviewParameters`` and a ``UIPreviewTarget``
/// object. Create the ``UIPreviewTarget`` object with your text view as the
/// container, and set the center point to the center of your text view.
/// Create the ``UIPreviewParameters`` object using the selection rectangles
/// for the text, which you get from your view’s layout manager. Writing Tools
/// uses this information to place your image directly above the text in your view.
///
/// For a single animation type, the system calls this method, followed sequentially
/// by the ``writingToolsCoordinator(_:prepareFor:range:context:completion:)`` and
/// ``writingToolsCoordinator(_:finish:for:in:completion:)``
/// methods. Each method executes asynchronously, but the system calls the next
/// method in the sequence only after you call the completion handler of the
/// previous method. However, multiple animations can run simultaneously, so
/// check the `textAnimation` parameter to differentiate sequences.
- (void)writingToolsCoordinator:(UIWritingToolsCoordinator *)writingToolsCoordinator requestsPreviewForTextAnimation:(UIWritingToolsCoordinatorTextAnimation)textAnimation ofRange:(NSRange)range inContext:(UIWritingToolsCoordinatorContext *)context completion:(void(^)(UIView * _Nullable))completion NS_SWIFT_ASYNC_NAME(writingToolsCoordinator(_:previewFor:range:context:));
#else // } {
/// Asks the delegate for a preview image and layout information for the
/// specified text.
///
/// - Parameters:
///    - writingToolsCoordinator: The coordinator object notifying you that
///    animations are about to begin.
///    - textAnimation: The type of animation Writing Tools is preparing.
///    - range: The range of text that requires a preview image. This range
///    is relative to the text in your context object, and it’s your responsibility
///    to match that location to the correct location in your text storage.
///    If you initialized the context object with the entire contents of
///    your view’s text storage, you can use `range` as-is to access that
///    text storage. However, if you initialized the context object with only
///    a portion of your view’s text, add the starting location of your
///    context object’s text to this value to get the correct range for that
///    text storage.
///    - context: The context object that contains the original text. Use this
///    object to fetch the current text, and to match that text to your
///    underlying text storage.
///    - completion: A completion handler to execute when you are done. The
///    handler has no return value and takes a ``UITargetedPreview`` object
///    as a parameter. You must call this handler at some point during your implementation.
///
/// During an interactive evaluation of your view’s text, Writing Tools creates
/// different animations to provide feedback on what’s happening. As part of
/// the preparation for those animations, Writing Tools asks you to provide
/// a preview of the affected content in your view. Writing Tools uses this
/// preview to build and execute the animations in the view stored in the
/// ``UIWritingToolsCoordinator/effectContainerView`` property of the coordinator object.
///
/// To build a preview of your content in iOS, render the specified range of
/// text into an image with a transparent background. Install the image in a
/// ``UIImageView`` and use that to build your preview object. Set the frame
/// rectangle of your image view to the rectangle in your view’s coordinate
/// space that contains the text you captured. When creating the ``UITargetedPreview``
/// object, include both a ``UIPreviewParameters`` and a ``UIPreviewTarget``
/// object. Create the ``UIPreviewTarget`` object with your text view as the
/// container, and set the center point to the center of your text view.
/// Create the ``UIPreviewParameters`` object using the selection rectangles
/// for the text, which you get from your view’s layout manager. Writing Tools
/// uses this information to place your image directly above the text in your view.
///
/// For a single animation type, the system calls this method, followed sequentially
/// by the ``writingToolsCoordinator(_:prepareFor:range:context:completion:)`` and
/// ``writingToolsCoordinator(_:finish:for:in:completion:)``
/// methods. Each method executes asynchronously, but the system calls the next
/// method in the sequence only after you call the completion handler of the
/// previous method. However, multiple animations can run simultaneously, so
/// check the `textAnimation` parameter to differentiate sequences.
- (void)writingToolsCoordinator:(UIWritingToolsCoordinator *)writingToolsCoordinator requestsPreviewForTextAnimation:(UIWritingToolsCoordinatorTextAnimation)textAnimation ofRange:(NSRange)range inContext:(UIWritingToolsCoordinatorContext *)context completion:(void(^)(UITargetedPreview * _Nullable))completion NS_SWIFT_ASYNC_NAME(writingToolsCoordinator(_:previewFor:range:context:));
#endif // }

/// Asks the delegate to clean up any state related to the specified
/// Writing Tools animation.
///
/// - Parameters:
///    - writingToolsCoordinator: The coordinator object notifying you
///    that animations are about to begin.
///    - textAnimation: The type of animation Writing Tools finished.
///    - range: The range of text that finished animating. This range is
///    relative to the text in your context object, and it’s your responsibility
///    to match that location to the correct location in your text storage. If
///    you initialized the context object with the entire contents of your
///    view’s text storage, you can use `range` as-is to access that text storage.
///    However, if you initialized the context object with only a portion of
///    your view’s text, add the starting location of your context object’s
///    text to this value to get the correct range for that text storage.
///    - context: The context object that contains the original text.
///    - completion: A completion handler to execute when you are done.
///    The handler has no return value and takes no parameters. You must
///    call this handler at some point during your implementation.
///
/// Use this method to clean up any data structures you created to support
/// the specified type of Writing Tools animation. You can also use this
/// method to restore the visibility of any text you hid previously. When
/// you finish your cleanup work, call the completion handler to notify Writing Tools.
///
/// Writing Tools calls this method only after previous calls to the
/// ``writingToolsCoordinator(_:requestsPreviewFor:range:context:completion:)``
/// and ``writingToolsCoordinator(_:prepareFor:range:context:completion:)``
/// methods for the same animation type. However, Writing Tools can interleave
/// calls to this method with calls to prepare an animation of a different
/// type. In your implementation of this method, make sure the actions you
/// take don’t interfere with other in-flight animations.
- (void)writingToolsCoordinator:(UIWritingToolsCoordinator *)writingToolsCoordinator finishTextAnimation:(UIWritingToolsCoordinatorTextAnimation)textAnimation forRange:(NSRange)range inContext:(UIWritingToolsCoordinatorContext *)context completion:(void(^)(void))completion;

@optional 

// Multiple container support

// The UITargetedPreview's previewTarget's container will be used for a coordinate conversion into the effectContainerView

/// Asks the delegate to divide the specified range of text into the separate
/// containers that render that text.
///
/// - Parameters:
///     - writingToolsCoordinator: The coordinator object requesting information
///     from your custom view.
///     - range: The range of text to consider in the specified `context` object.
///     The location value of this range is relative to the beginning of the text
///     in your context object, and it’s your responsibility to match that location
///     to the correct location in your text storage. If you initialized the
///     context object with the entire contents of your view’s text storage,
///     you can use `range` as-is to access that text storage. However, if you
///     initialized the context object with only a portion of your view’s text,
///     add the starting location of your context object’s text to this value
///     to get the correct range for that text storage.
///     - context: The context object that contains the text to consider. Use this
///     object to locate the appropriate text storage object for your view.
///     - completion: A completion handler to execute when you are done. The handler
///     has no return value and takes an array of <doc://com.apple.documentation/documentation/foundation/nsvalue>
///     types, each of which contains an <doc://com.apple.documentation/documentation/foundation/nsrange>.
///     The union of the ranges you pass to this handler must equal all of the
///     text in `range`. The order of the ranges in the array must be sequential,
///     with each new range's starting location coming after the previous one.
///     There must also not be any gaps or overlap between ranges.
///     You must call this handler at some point during your implementation.
///
/// If your view uses multiple ``NSTextContainer`` objects to draw text in different
/// regions, use this method to tell Writing Tools about the containers that display
/// the specified text. In your implementation, subdivide `range` to create one new
/// range for each portion of text that resides in a different container object.
/// For example, if the text in `range` is split between two containers, provide
/// two new <doc://com.apple.documentation/documentation/foundation/nsrange> types
/// that reflect the portion of the total text in each container. If `range` resides completely
/// within one container, call the completion handler with `range` as the only value
/// in the array.
///
/// When configuring animations for your view, Writing Tools asks your delegate to
/// provide separate previews for each of your view’s container object. Specifically,
/// it calls your delegate’s ``writingToolsCoordinator(_:requestsPreviewFor:range:context:completion:)``
/// method separately for each range of text you return in the completion handler.
/// Your implementation of that method must create a preview suitable for animating
/// the content from the underlying text container.
- (void)writingToolsCoordinator:(UIWritingToolsCoordinator *)writingToolsCoordinator requestsSingleContainerSubrangesOfRange:(NSRange)range inContext:(UIWritingToolsCoordinatorContext *)context completion:(void(^)(NSArray<NSValue */*NSRange*/> *))completion NS_SWIFT_ASYNC_NAME(writingToolsCoordinator(_:singleContainerSubrangesOf:in:));

/// Asks the delegate to provide a decoration view for the specified range of text.
///
/// - Parameters:
///     - writingToolsCoordinator: The coordinator object requesting information
///     from your custom view.
///     - range: The range of text to consider in the specified `context` object.
///     The location value of this range is relative to the beginning of the text
///     in your context object, and it’s your responsibility to match that location
///     to the correct location in your text storage. If you initialized the
///     context object with the entire contents of your view’s text storage, you
///     can use `range` as-is to access that text storage. However, if you initialized
///     the context object with only a portion of your view’s text, add the starting
///     location of your context object’s text to this value to get the correct
///     range for that text storage.
///     - context: The context object that contains the text to consider. Use this
///     object to locate the appropriate text storage object for your view.
///     - completion: A completion handler to execute when you are done. The handler
///     has no return value and takes a ``UIView`` object as a parameter. You must call
///     this handler at some point during your implementation.
///
/// If your view uses multiple ``NSTextContainer`` objects to draw text in different
/// regions, use this method to provide Writing Tools with the view to use for the
/// specified range of text. After calling your delegate’s ``writingToolsCoordinator(_:requestsSingleContainerSubrangesOf:in:completion:)``
/// method, Writing Tools calls this method for each subrange of text you provided.
/// Find or provide a view situated visibly below the specified text in your text
/// view. It's also satisfactory to provide a view that’s visually in front of the
/// text. Writing Tools uses the provided view to host any proofreading marks for
/// the specified range of text.
///
/// If your view has only one text container, use the coordinator’s ``UIWritingToolsCoordinator/decorationContainerView``
/// property to specify the view to use for proofreading marks.
- (void)writingToolsCoordinator:(UIWritingToolsCoordinator *)writingToolsCoordinator requestsDecorationContainerViewForRange:(NSRange)range inContext:(UIWritingToolsCoordinatorContext *)context completion:(void(^)(UIView *))completion NS_SWIFT_ASYNC_NAME(writingToolsCoordinator(_:decorationContainerViewFor:in:));

// Lifecycle

// Possible state changes
//  Inactive -> Noninteractive
//  Noninteractive -> Inactive
//  Inactive -> InteractiveResting
//  InteractiveResting -> InteractiveStreaming
//  InteractiveResting -> Inactive
//  InteractiveStreaming -> InteractiveResting
//  InteractiveStreaming -> Inactive

/// Notifies your delegate of relevant state changes when Writing Tools
/// is running in your view.
///
/// - Parameters:
///     - writingToolsCoordinator: The coordinator object providing
///     information to your custom view.
///     - state: The new state for the Writing Tools session. For information
///     about the possible states, see ``UIWritingToolsCoordinator/State``.
///     - text: The current text for your context object.
///     - reason: The reason for the state change.
///     - context: The context object that contains the original text for
///     Writing Tools to evaluate.
///     - completion: A handler to execute when your delegate finishes processing
///     the change of state. The handler has no parameters or return value. You
///     must call this handler at some point during the implementation of your method.
///
/// Use state transitions to perform actions related to your view or text storage.
/// When Writing Tools is active, it updates its state to indicate what task
/// it’s currently performing. Writing Tools starts in the ``UIWritingToolsCoordinator/State/inactive``
/// state and moves to other states as it presents UI and starts interacting with
/// your view’s content. For example, it moves to the ``UIWritingToolsCoordinator/State/interactiveStreaming``
/// state when it’s making changes to your view’s text storage.
- (void)writingToolsCoordinator:(UIWritingToolsCoordinator *)writingToolsCoordinator willChangeToState:(UIWritingToolsCoordinatorState)newState completion:(void(^)(void))completion;


// Deprecated. Not called in iOS 18.4 or visionOS 2.4 or later

/// Asks the delegate to provide the location of the character at the
/// specified point in your view’s coordinate system.
///
/// - Parameters:
///     - writingToolsCoordinator: The coordinator object requesting
///     information from your custom view.
///     - point: A point in your view’s coordinate space. Find the
///     location of the text under this point, if any.
///     - completion: A handler to execute with the required information.
///     This handler has no return value and takes an <doc://com.apple.documentation/documentation/foundation/nsrange>
///     and <doc://com.apple.documentation/documentation/foundation/uuid>
///     as parameters. Set the range to the character’s location in one of your
///     ``UIWritingToolsCoordinator/Context`` objects, which you specify using
///     the <doc://com.apple.documentation/documentation/foundation/uuid> parameter.
///     You must call this handler at some point during your method’s implementation.
///
/// When someone interacts with your view during a proofreading operation, Writing Tools
/// calls this method to get the location of the interaction. If the interaction
/// occurs in the text of one of your ``UIWritingToolsCoordinator/Context`` objects,
/// configure an <doc://com.apple.documentation/documentation/foundation/nsrange>
/// with the character’s location in that context object and a length of `1`. If
/// the interaction occurs outside of the text of your context objects, configure
/// the range with a location of `NSNotFound`.
///
/// When specifying the location of a character in your context object, provide a
/// location relative to the start of your context object’s text. The first character
/// in a context object’s text is always at location `0`, and it’s your responsibility
/// to track the location of the context object’s text in your text storage object.
/// When the context object’s text begins in the middle of your text storage,
/// subtract the starting location of the context object’s text from the location
/// you specify in your range value. For example, if the context object’s text
/// starts at character `100` in your text storage, and an interaction occurs
/// with the character at location `102`, specify a range with a location of
/// `2` and a length of `1`.
- (void)writingToolsCoordinator:(UIWritingToolsCoordinator *)writingToolsCoordinator requestsRangeInContextWithIdentifierForPoint:(CGPoint)point completion:(void(^)(NSRange range, NSUUID *contextID))completion API_DEPRECATED("In iOS 18.4 and later and visionOS 2.4 and later, UIWritingToolsCoordinator automatically determines the location of the character at the specified point in your view's coordinate system and no longer calls this method.", ios(18.2,18.4)) API_UNAVAILABLE(visionos) NS_SWIFT_ASYNC_NAME(writingToolsCoordinator(_:rangeInContextWithIdentifierFor:));

@end
NS_HEADER_AUDIT_END(nullability, sendability)

#else
#import <UIKitCore/UIWritingToolsCoordinator.h>
#endif
