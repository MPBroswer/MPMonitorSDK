#
# Be sure to run `pod lib lint MPMonitorSDK.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'MPMonitorSDK'
  s.version          = '0.0.3'
  s.summary          = 'MPMonitorSDK Cocoapods集成库'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'https://github.com/MPBroswer/MPMonitorSDK'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'MPBroswer' => 'MPDeveloper@163.com' }
  s.source           = { :git => 'https://github.com/MPBroswer/MPMonitorSDK.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  # 支持的平台及版本
  s.platform     = :ios, "11.0"
  # iOS支持的pod最低版本 / iOS对应的版本
  s.ios.deployment_target = "11.0"

  # 使用了第三方静态库
  # s.ios.vendored_library = ''
  #s.ios.vendored_libraries = ''
  s.ios.vendored_frameworks = 'MPMonitorSDK.xcframework'

  # 是否使用ARC，如果指定具体文件，则具体的问题使用ARC
  s.requires_arc = true

  s.swift_versions = ['5']
end
