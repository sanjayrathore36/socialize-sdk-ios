platform :ios, '6.1'
inhibit_all_warnings!
xcodeproj 'Socialize.xcodeproj'

link_with 'TestApp'
pod 'SZFacebook', :path => './ThirdParty/facebook-ios-sdk'
pod 'Socialize', :path => '.'

#copy resources from Loopy to include in framework
#post_install do | installer |
#  require 'fileutils'
#  FileUtils.cp_r(Dir['Pods/Loopy/Loopy/Resources/*'], 'Socialize/Resources', :remove_destination => true)
#  FileUtils.cp_r('Pods/Loopy/Loopy/LoopyApiInfo.plist', 'Socialize/Resources', :remove_destination => true)
#end