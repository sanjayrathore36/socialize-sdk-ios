platform :ios, '6.1'
inhibit_all_warnings!
xcodeproj 'Socialize.xcodeproj'

link_with 'Socialize-new'
pod 'Loopy', :podspec => 'https://raw.github.com/socialize/loopy-sdk-ios/master/Loopy.podspec'
pod 'Facebook-iOS-SDK', '~> 3.9.0'

target 'UIIntegrationAcceptanceTests', :exclusive => true do
  pod 'KIF', '~> 2.0'
end

#copy resources from Loopy to include in framework
post_install do | installer |
  require 'fileutils'
  FileUtils.cp_r(Dir['Pods/Loopy/Loopy/Resources/*'], 'Socialize/Resources', :remove_destination => true)
  FileUtils.cp_r('Pods/Loopy/Loopy/LoopyApiInfo.plist', 'Socialize/Resources', :remove_destination => true)
end