# mpp-playground
Kotlin Multiplatform Project Playground

## Dependencies
- Networking : [http-client-common](https://github.com/Kotlin/kotlinx.serialization)
- JSON Parser/ Serialization : [kotlinx.serializations](https://github.com/Kotlin/kotlinx.serialization)
- Async Programming : [kotlinx.coroutines](https://github.com/Kotlin/kotlinx.coroutines)

## Project Structure
- [mpp-playground-common](https://github.com/RR12/mpp-playground/tree/master/mpp-playground-common) : Kotlin Multiplatform's Common module. Contains Business logic, Data class and all shared element.
- [mpp-playground-jvm](https://github.com/RR12/mpp-playground/tree/master/mpp-playground-jvm) : JVM Platform specific implementation.
- mpp-playground-ios : iOS Platform specific implementation.
- [mpp-playground-client-android](https://github.com/RR12/mpp-playground/tree/master/mpp-playground-client-android) : Android application that will using the shared code.
- mpp-playground-client-ios : iOS application that will using the shared code.
