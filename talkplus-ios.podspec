Pod::Spec.new do |s|
  s.name = "talkplus-ios"
  s.version = "0.0.7"
  s.summary = "A short description of talkplus-ios."
  s.license = {"type"=>"MIT", "file"=>"LICENSE"}
  s.authors = {"Chiung Choi"=>"god@adxcorp.kr"}
  s.homepage = "https://github.com/adxcorp/talkplus-ios"
  s.description = "TODO: Add long description of the pod here."
  s.xcconfig = {"CLANG_ALLOW_NON_MODULAR_INCLUDES_IN_FRAMEWORK_MODULES"=>"YES"}
  s.source = { :git => 'https://github.com/adxcorp/talkplus-ios-release.git', :tag => s.version.to_s }

  s.ios.deployment_target    = '9.0'
  s.ios.vendored_framework   = 'ios/talkplus-ios.framework'

  s.dependency 'AWSIoT', '2.16.0'
  
  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  s.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64', 'CLANG_ALLOW_NON_MODULAR_INCLUDES_IN_FRAMEWORK_MODULES' => 'YES' }
  s.xcconfig = { 'CLANG_ALLOW_NON_MODULAR_INCLUDES_IN_FRAMEWORK_MODULES' => 'YES' }
end
