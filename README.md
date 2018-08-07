# mpp-playground
Kotlin Multiplatform Project Playground

## Dependencies
- Networking : [http-client-common](https://github.com/Kotlin/kotlinx.serialization)
- JSON Parser/ Serialization : [kotlinx.serializations](https://github.com/Kotlin/kotlinx.serialization)
- Async Programming : [kotlinx.coroutines](https://github.com/Kotlin/kotlinx.coroutines)

## Project Structure
- [mpp-playground-common](https://github.com/RR12/mpp-playground/tree/master/mpp-playground-common) : Kotlin Multiplatform's Common module. Contains Business logic, Data class and all shared element.
- [mpp-playground-jvm](https://github.com/RR12/mpp-playground/tree/master/mpp-playground-jvm) : JVM Platform specific implementation.
- [mpp-playground-native](https://github.com/RR12/mpp-playground/tree/master/mpp-playground-native) : iOS Platform specific implementation.
- [mpp-playground-client-android](https://github.com/RR12/mpp-playground/tree/master/mpp-playground-client-android) : Android application that will using the shared code.
- [mpp-playground-client-ios](https://github.com/RR12/mpp-playground/tree/master/mpp-playground-client-ios) : iOS application that will using the shared code.

## TODO
* [ ] Better multi-threading mechanism for each platform. Kotlin Coroutines still gives [this issue](https://github.com/JetBrains/kotlin-native/issues/1815) and the Libarary its self isn't quite ready yet to support Kotlin/Native([Feature request](https://github.com/Kotlin/kotlinx.coroutines/issues/462))
* [ ] Common Networking solution. Will using [http-client-common](https://github.com/Kotlin/kotlinx.serialization), but for now it still gives us error. Waiting [this feature](https://github.com/Kotlin/kotlinx.coroutines/issues/462) to be ready in Kotlin Coroutines library 
