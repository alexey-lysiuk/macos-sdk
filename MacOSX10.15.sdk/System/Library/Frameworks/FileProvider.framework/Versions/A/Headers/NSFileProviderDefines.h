//
//  NSFileProviderDefines.h
//  FileProvider
//
//  Copyright © 2017-2020 Apple Inc. All rights reserved.
//

#ifndef PREPROCESS_AVAILABILITY_MACROS

// changing anything here? be sure to also change process-header.sh!

#define FILEPROVIDER_SPI_AVAILABILITY API_UNAVAILABLE(watchos, tvos)

#define FILEPROVIDER_CLASS_AVAILABILITY API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos, macCatalyst) API_UNAVAILABLE(watchos, tvos)
#define FILEPROVIDER_API_AVAILABILITY_V2 API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(macos, macCatalyst) API_UNAVAILABLE(watchos, tvos)
#define FILEPROVIDER_API_AVAILABILITY_V2_V3 API_AVAILABLE(ios(11.0), macos(10.15)) API_UNAVAILABLE(macCatalyst) API_UNAVAILABLE(watchos, tvos)
#define FILEPROVIDER_API_AVAILABILITY_V3 API_UNAVAILABLE(macos) API_UNAVAILABLE(watchos, tvos) API_UNAVAILABLE(ios, macCatalyst)

#else
// This file intentionally left blank.
#endif
