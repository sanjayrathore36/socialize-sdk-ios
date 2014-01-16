platform :ios, '6.1'
inhibit_all_warnings!
xcodeproj 'Socialize.xcodeproj'

link_with 'TestApp'
pod 'SZFacebook', :path => './ThirdParty/facebook-ios-sdk'
pod 'SZBlocksKit', :path => './ThirdParty/BlocksKit/SZBlocksKit.podspec'
pod 'SZJSONKit', :path => './ThirdParty/JSONKit/SZJSONKit.podspec'
pod 'SZOAuthConsumer', :path => './ThirdParty/OAuthConsumer/SZOAuthConsumer.podspec'
pod 'Loopy', :podspec => 'https://raw.github.com/socialize/loopy-sdk-ios/master/Loopy.podspec'
pod 'Socialize', :path => '.'


target :loopy, :exclusive => true do
	link_with 'Socialize', 'Socialize-profiling'
	pod 'Loopy', :podspec => 'https://raw.github.com/socialize/loopy-sdk-ios/master/Loopy.podspec'
end

#copy resources from Loopy to include in framework
#post_install do | installer |
#  require 'fileutils'
#  FileUtils.cp_r(Dir['Pods/Loopy/Loopy/Resources/*'], 'Socialize/Resources', :remove_destination => true)
#  FileUtils.cp_r('Pods/Loopy/Loopy/LoopyApiInfo.plist', 'Socialize/Resources', :remove_destination => true)
#end