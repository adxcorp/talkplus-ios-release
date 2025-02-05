
# Klat-iOS

![Platforms](https://img.shields.io/cocoapods/p/talkplus-ios.svg)
![Swift Package Manager](https://img.shields.io/badge/SPM-compatible-green.svg)
![CocoaPods](https://img.shields.io/badge/CocoaPods-compatible-green.svg)
![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)

## 요구사항

Klat iOS SDK 사용을 위한 최소 요구사항
- Xcode 15.0+
- iOS 10.0+
<br/>

## SDK 설치

Klat iOS SDK는 [CocoaPods](https://cocoapods.org) 또는 [Swift Package Manager](https://swift.org/package-manager/)를 사용하여 설치할 수 있습니다.
<br/>

### 코코아팟 (CocoaPods)
```ruby
pod 'talkplus-ios'
```

macOS에서 터미널 (Terminal) 실행하고,  iOS 앱 프로젝트 디렉토리로 이동 한 다음에 아래 명령어를 활용하여 `Podfile`을 열어 주십시오.

```bash
$ open Podfile
```

아래와 같이 `Podfile` 파일에 `pod 'talkplus-ios'` 를 추가하여 주십시오.

```bash
platform :ios, '12.0'
 
target 'Project' do
    use_frameworks!
    pod 'talkplus-ios'
end
```

**CocoaPods CLI** 명령어를 이용하여 SDK 설치를 완료하여 주십시오.

```bash
$ pod install --repo-update
```
<br/>

### 스위프트 패키지 매니저 (Swift Package Manager)

### Swift Package Manager
>1) Xcode에서 아래 메뉴를 클릭합니다.
   Xcode - File -> Add Package Dependencies...
>2) 우측 상단 패키지 URL에 아래 저장소 URL를 입력합니다.
   https://github.com/adxcorp/talkplus-ios-release.git
>3) 사용하려는 버전을 선택하고 "Add Package" 버튼을 클릭하여 SDK 설치를 완료합니다.