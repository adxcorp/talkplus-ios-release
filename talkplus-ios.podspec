Pod::Spec.new do |s|
  s.name = "talkplus-ios"
  s.version = "0.5.5"
  s.summary = "A short description of talkplus-ios."
  s.license = {"type"=>"MIT"}
  s.authors = {"Chiung Choi"=>"god@adxcorp.kr"}
  s.homepage = "https://www.talkplus.io/"
  s.description = "TODO: Add long description of the pod here."
  s.source = { :git => 'https://github.com/adxcorp/talkplus-ios-release.git', :tag => s.version.to_s }

  s.ios.deployment_target = '10.0'
  s.ios.vendored_framework = 'ios/TalkPlus.xcframework'

end
