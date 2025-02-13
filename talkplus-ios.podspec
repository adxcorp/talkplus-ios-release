Pod::Spec.new do |s|
  s.name = "talkplus-ios"
  s.version = "1.0.1"
  s.summary = "Klat Chat SDK for iOS"
  s.license = {"type"=>"MIT"}
  s.author = "Neptune Company"
  s.homepage = "https://www.klat.kr"
  s.description = "Klat Chat SDK for iOS"
  s.source = { :http => "https://github.com/adxcorp/talkplus-ios-release/archive/refs/tags/#{s.version}.tar.gz"}
  s.ios.deployment_target = '10.0'
  s.ios.vendored_framework = 'ios/TalkPlus.xcframework'
end
