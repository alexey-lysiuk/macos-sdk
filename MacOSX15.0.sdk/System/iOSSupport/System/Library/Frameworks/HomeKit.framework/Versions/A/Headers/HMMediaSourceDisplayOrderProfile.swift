//
//  HMMediaSourceDisplayOrderProfile.swift
//  HomeKit
//
//  Copyright © 2024 Apple Inc. All rights reserved.
//

internal import HomeKit_Internal

///
/// @abstract Represents media source display ordering functionality for an HMServiceTypeTelevision service that is contained in the services array for this profile.
///
/// @discussion Provides an interface to read and, if allowed by the accessory, update the ordering of input sources.
///
@available(iOS 18.0, watchOS 11.0, tvOS 18.0, visionOS 2.0, *)
@_spi_available(macOS 15, *)
public class HMMediaSourceDisplayOrderProfile: HMAccessoryProfile, @unchecked Sendable {
    /// @brief This defines the protocol for a delegate to receive updates about the ordering of input media sources.
    @available(iOS 18.0, watchOS 11.0, tvOS 18.0, visionOS 2.0, *)
    @_spi_available(macOS 15, *)
    public protocol Delegate: AnyObject, Sendable {
        ///
        /// @brief Informs the delegate when the media source display order is modified.
        ///
        /// @param profile                   The profile whose display order has been updated.
        ///
        func mediaSourceDisplayOrderProfileDidUpdateOrder(_ profile: HMMediaSourceDisplayOrderProfile)
    }

    private let televisionProfile: _HMTelevisionProfile
    private let displayOrderProfileDelegateAdaptor: HMTelevisionProfileDelegateAdaptor?

    /// @brief Indicates if the display order of input media sources can be modified.
    public let canModifyOrder: Bool

    ///
    /// @brief       Display order of input media sources.
    ///
    /// @discussion  The entries are the HMCharacteristicTypeIdentifier values for HMServiceTypeInputSource
    ///              services in the set of services associated with this profile.
    ///
    public var order: [Int] {
        return televisionProfile.mediaSourceDisplayOrder?.map { $0.intValue } ?? []
    }

    public weak var delegate: Delegate?

    ///
    /// @abstract   Writes the display order of the media sources to the accessory.
    ///
    /// @param      order The new display order for the media sources. The media source entries are the HMCharacteristicTypeIdentifier
    ///             values for HMServiceTypeInputSource services in the set of services associated with this profile.
    ///
    /// @returns    An error will be thrown if the source ordering fails to be written to the accessory.
    ///
    public func writeOrder(_ order: [Int]) async throws {
        try await self.televisionProfile.updateMediaSourceDisplayOrder(order.map { NSNumber(value: $0) })
    }

    @objc
    internal required init(televisionProfile: _HMTelevisionProfile) {
        self.televisionProfile = televisionProfile
        self.canModifyOrder = televisionProfile.mediaSourceDisplayOrderModifiable
        displayOrderProfileDelegateAdaptor = HMTelevisionProfileDelegateAdaptor(televisionProfile: televisionProfile)
        super.init(accessoryProfile: televisionProfile)
        displayOrderProfileDelegateAdaptor?.displayOrderProfile = self
    }

    @available(*, unavailable)
    override init(accessoryProfile: _HMAccessoryProfile) {
        fatalError("\(#function) is unavailable")
    }

    // Since _HMTelevisionProfileDelegate is an internal type we cant have the public class HMMediaSourceDisplayOrderProfile conform to it as that
    // would need to be exported publicly so we can use this private class to shim it
    private class HMTelevisionProfileDelegateAdaptor: NSObject, _HMTelevisionProfileDelegate {
        func televisionProfileDidUpdateSourceDisplayOrder(_ televisionProfile: _HMTelevisionProfile) {
            guard let displayOrderProfile else { return }
            televisionProfile.context.delegateCaller.invokeBlock {
                displayOrderProfile.delegate?.mediaSourceDisplayOrderProfileDidUpdateOrder(displayOrderProfile)
            }
        }

        let televisionProfile: _HMTelevisionProfile
        weak var displayOrderProfile: HMMediaSourceDisplayOrderProfile?

        init(televisionProfile: _HMTelevisionProfile) {
            self.televisionProfile = televisionProfile
            super.init()
            self.televisionProfile.delegate = self
        }
    }
}
