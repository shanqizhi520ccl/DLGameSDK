Pod::Spec.new do |s| 
  s.name         = "DLGameSDK"      #SDK名称
  s.version      = "1.0.0"                        #版本号
  s.homepage     = "https://github.com/shanqizhi520ccl/DLGameSDK"  #工程主页地址
  s.summary      = "DLGameSDK是用来自身项目使用的"  #项目的简单描述
  s.license  = "MIT"  #协议类型
  s.author       = { "Seven" => "shanqizhi_seven@163.com" } #作者及联系方式
  s.platform     = :ios  #支持的平台
  s.platform     = :ios, "12.0"   #平台及版本
  s.ios.deployment_target = "12.0"     #最低系统版本
  s.source       = { :git => "https://github.com/shanqizhi520ccl/DLGameSDK.git" ,:tag => "#{s.version}"}   #工程地址及版本号
  s.requires_arc = true   #是否必须arc
  s.source_files = "Users/shanqizhi/Desktop/DLGameSDK/DLGameSDK.framework/Headers/DLGameSDK.h"   #SDK实际的重要文件路径，这里有个坑，后面文章再说
  s.frameworks   = "UIKit","Foundation"    #需要导入的frameworks名称，注意不要带上frameworks
end