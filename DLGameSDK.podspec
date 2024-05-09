Pod::Spec.new do |s|
  s.name             = 'DLGameSDK'
  s.version          = '4.0.0'
  s.summary          = '更新DLGameSDK v4.0.0版本'
  s.description      = 'An optional longer description of DLGameSDK.'
  s.homepage         = 'https://github.com/shanqizhi520ccl/DLGameSDK'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'Seven' => 'shanqizhi_seven@163.com' }
  s.source           = { :git => 'https://github.com/shanqizhi520ccl/DLGameSDK.git', :tag => s.version.to_s }
  s.ios.deployment_target = '12.0'
  s.platform         = :ios, '12.0'
  s.frameworks       = 'UIKit', 'Foundation'
  s.requires_arc     = true
  s.source_files     = 'DLGameSDK.framework/Headers/*.{h}'
end
