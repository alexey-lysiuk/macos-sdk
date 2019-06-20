#if (defined(USE_UIKIT_PUBLIC_HEADERS) && USE_UIKIT_PUBLIC_HEADERS) || !__has_include(<UIKitCore/UICommandBuilder.h>)
//
//  UICommandBuilder.h
//  UIKit
//
//  Copyright (c) 2019 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <UIKit/UICommandGroup.h>
#import <UIKit/UIMenu.h>

@class UICommandSystem;
@class UICommand;

NS_ASSUME_NONNULL_BEGIN

/// Encapsulates access and mutation for a command group hierarchy.
API_AVAILABLE(ios(13.0)) @protocol UICommandBuilder

/// Which system we are building for.
@property (nonatomic, readonly) UICommandSystem *system;

/// Fetch the identified menu.
///
/// @param identifier The identifier of the menu to fetch.
/// @return The menu with the given identifier, or `nil` if no such menu.
- (nullable UIMenu<UICommand *> *)menuForIdentifier:(UIMenuIdentifier)identifier NS_SWIFT_NAME(menu(for:));

/// Fetch the identified command.
///
/// @param action The action of the command to find.
/// @param propertyList Property list object to distinguish commands, if needed.
/// @return The command with the given action and property list, or `nil` if no such command.
- (nullable UICommand *)commandForAction:(SEL)action propertyList:(nullable id)propertyList NS_REFINED_FOR_SWIFT;

/// Replace an identified menu with a menu.
///
/// @param replacedIdentifier The identifier of the menu to be replaced.
/// @param replacementGroup The replacement menu.
- (void)replaceMenuForIdentifier:(UIMenuIdentifier)replacedIdentifier withMenu:(UIMenu<UICommand *> *)replacementMenu NS_SWIFT_NAME(replace(menu:with:));

/// Replace the children of an identified parent menu.
///
/// @param parentIdentifier The identifier of the parent menu.
/// @param childrenBlock A block that returns the new children, given the old children.
- (void)replaceChildrenOfMenuForIdentifier:(UIMenuIdentifier)parentIdentifier
                         fromChildrenBlock:(NSArray<UIMenuElement<UICommand *> *> *(NS_NOESCAPE ^)(NSArray<UIMenuElement<UICommand *> *> *))childrenBlock NS_SWIFT_NAME(replaceChildren(ofMenu:from:));

/// Insert a sibling menu before an identified sibling menu.
///
/// @param siblingGroup The sibling menu to insert.
/// @param siblingIdentifier The identifier of the sibling menu to insert before.
- (void)insertSiblingMenu:(UIMenu<UICommand *> *)siblingMenu beforeMenuForIdentifier:(UIMenuIdentifier)siblingIdentifier NS_SWIFT_NAME(insertSibling(_:beforeMenu:));

/// Insert a sibling menu before an identified sibling menu.
///
/// @param siblingGroup The sibling menu to insert.
/// @param siblingIdentifier The identifier of the sibling menu to insert before.
- (void)insertSiblingMenu:(UIMenu<UICommand *> *)siblingMenu afterMenuForIdentifier:(UIMenuIdentifier)siblingIdentifier NS_SWIFT_NAME(insertSibling(_:afterMenu:));

/// Insert a child menu at the start of an identified parent menu.
///
/// @param childGroup The child menu to insert.
/// @param parentIdentifier The identifier of the parent menu to insert at the start of.
- (void)insertChildMenu:(UIMenu<UICommand *> *)childMenu atStartOfMenuForIdentifier:(UIMenuIdentifier)parentIdentifier NS_SWIFT_NAME(insertChild(_:atStartOfMenu:));

/// Insert a child menu at the end of an identified parent menu.
///
/// @param childGroup The child menu to insert.
/// @param parentIdentifier The identifier of the parent menu to insert at the end of.
- (void)insertChildMenu:(UIMenu<UICommand *> *)childMenu atEndOfMenuForIdentifier:(UIMenuIdentifier)parentIdentifier NS_SWIFT_NAME(insertChild(_:atEndOfMenu:));

/// Remove an identified menu.
///
/// @param removedIdentifier The menu to remove.
- (void)removeMenuForIdentifier:(UIMenuIdentifier)removedIdentifier NS_SWIFT_NAME(remove(menu:));

/** START OF V1 API, TO REMOVE **/

/// Fetch the identified group.
///
/// @param identifier The identifier of the group to fetch.
/// @return The group with the given identifier, or `nil` if no such group.
- (nullable UICommandGroup *)groupForIdentifier:(UICommandGroupIdentifier)identifier NS_SWIFT_NAME(group(_:)) API_DEPRECATED_WITH_REPLACEMENT("menuForIdentifier:", ios(13.0, 13.0));

/// Replace an identified group with a group.
///
/// @param replacedIdentifier The identifier of the group to be replaced.
/// @param replacementGroup The replacement group.
- (void)replaceGroupForIdentifier:(UICommandGroupIdentifier)replacedIdentifier withGroup:(UICommandGroup *)replacementGroup NS_SWIFT_NAME(replace(group:with:)) API_DEPRECATED_WITH_REPLACEMENT("replaceMenuForIdentifier:withMenu:", ios(13.0, 13.0));

/// Replace the children of an identified parent group.
///
/// @param parentIdentifier The identifier of the parent group.
/// @param childrenBlock A block that returns the new children, given the old children.
- (void)replaceChildrenOfGroupForIdentifier:(UICommandGroupIdentifier)parentIdentifier
                                  fromBlock:(NSArray<id<UICommandGroupable>> *(NS_NOESCAPE ^)(NSArray<id<UICommandGroupable>> *))childrenBlock NS_SWIFT_NAME(replaceChildren(ofGroup:from:))  API_DEPRECATED_WITH_REPLACEMENT("replaceChildrenOfMenuForIdentifier:fromChildrenBlock:", ios(13.0, 13.0));

/// Insert a sibling group before an identified sibling group.
///
/// @param siblingGroup The sibling group to insert.
/// @param siblingIdentifier The identifier of the sibling group to insert before.
- (void)insertSiblingGroup:(UICommandGroup *)siblingGroup beforeGroupForIdentifier:(UICommandGroupIdentifier)siblingIdentifier NS_SWIFT_NAME(insertSibling(_:beforeGroup:)) API_DEPRECATED_WITH_REPLACEMENT("insertSiblingMenu:beforeMenuForIdentifier:", ios(13.0, 13.0));

/// Insert a sibling group after an identified sibling group.
///
/// @param siblingGroup The sibling group to insert.
/// @param siblingIdentifier The identifier of the sibling group to insert after.
/// @return Whether the insertion succeeded.
- (void)insertSiblingGroup:(UICommandGroup *)siblingGroup afterGroupForIdentifier:(UICommandGroupIdentifier)siblingIdentifier NS_SWIFT_NAME(insertSibling(_:afterGroup:)) API_DEPRECATED_WITH_REPLACEMENT("insertSiblingMenu:afterMenuForIdentifier:", ios(13.0, 13.0));

/// Insert a child group at the start of an identified parent group.
///
/// @param childGroup The child group to insert.
/// @param parentIdentifier The identifier of the parent group to insert at the start of.
- (void)insertChildGroup:(UICommandGroup *)childGroup atStartOfGroupForIdentifier:(UICommandGroupIdentifier)parentIdentifier NS_SWIFT_NAME(insertChild(_:atStartOfGroup:))  API_DEPRECATED_WITH_REPLACEMENT("insertChildMenu:atStartOfMenuForIdentifier:", ios(13.0, 13.0));

/// Insert a child group at the end of an identified parent group.
///
/// @param childGroup The child group to insert.
/// @param parentIdentifier The identifier of the parent group to insert at the end of.
- (void)insertChildGroup:(UICommandGroup *)childGroup atEndOfGroupForIdentifier:(UICommandGroupIdentifier)parentIdentifier NS_SWIFT_NAME(insertChild(_:atEndOfGroup:)) API_DEPRECATED_WITH_REPLACEMENT("insertChildMenu:atEndOfMenuForIdentifier:", ios(13.0, 13.0));;

/// Remove an identified group.
///
/// @param removedIdentifier The group to remove.
- (void)removeGroupForIdentifier:(UICommandGroupIdentifier)removedIdentifier NS_SWIFT_NAME(remove(group:)) API_DEPRECATED_WITH_REPLACEMENT("removeMenuForIdentifier:", ios(13.0, 13.0));;

/** END OF V1 API, TO REMOVE **/

/** START OF V1 API, TO REMOVE **/

/// Find a command for an action.
///
/// @note If several commands have the same action, this method returns the first one in depth-first order.
/// @param action The action of the command to find.
/// @return The first command found with the given action, or `nil` if no such command.
- (nullable UICommand *)commandForAction:(SEL)action API_DEPRECATED_WITH_REPLACEMENT("commandForAction:propertyList:", ios(13.0, 13.0));

/** END OF V1 API, TO REMOVE **/

@end

NS_ASSUME_NONNULL_END

#else
#import <UIKitCore/UICommandBuilder.h>
#endif
