Pod::Spec.new do |s|
  s.name         = "Socialize"
  s.version      = "2.8.10"
  s.summary      = "Socialize iOS SDK"
  s.description  = "Socialize is the fastest way to make any app social. Our drop-in social platform creates a community around your app with commenting, sharing and social media integration. Not only does your app become more engaging, your content is spread throughout each users’ existing social networks—for more app discovery and a big ol’ boost in overall downloads. We like to call this “the loop”. And it gets your users working for you."
  s.homepage     = "http://getsocialize.com"
  s.license      = { :type => 'MIT', :file => 'FILE_LICENSE' }
  s.author       = { "Socialize, Inc" => "info@GetSocialize.com" }
  s.platform     = :ios, '6.1'
  s.source       = { :path => "."}
  s.requires_arc    = true
  s.default_subspec = 'Core'

  s.subspec 'Core' do |core|
    core.source_files        = 'Socialize/*.{h,m}'
    core.public_header_files = 'Socialize/*.h'
    core.subspec 'Core_no_arc' do |core_no_arc|
      core_no_arc.source_files = 'Socialize-noarc/**/*.{h,m}'
      core_no_arc.requires_arc    = false
      core_no_arc.dependency 'SZFacebook'
      core_no_arc.dependency 'SZBlocksKit'
      core_no_arc.dependency 'SZJSONKit'
      core_no_arc.dependency 'SZOAuthConsumer'
      core_no_arc.dependency 'Loopy'
    end
  end


  #s.source_files  = 'Classes', 'Classes/**/*.{h,m}'
  #s.exclude_files = 'Classes/Exclude'

  #s.public_header_files = 'Classes/**/*.h'



  # s.resource  = "icon.png"
  # s.resources = "Resources/*.png"

  # s.preserve_paths = "FilesToSave", "MoreFilesToSave"

  # s.framework  = 'SomeFramework'
  # s.frameworks = 'SomeFramework', 'AnotherFramework'

  # s.library   = 'iconv'
  # s.libraries = 'iconv', 'xml2'


  # s.requires_arc = true

  # s.xcconfig = { 'HEADER_SEARCH_PATHS' => '$(SDKROOT)/usr/include/libxml2' }
  # s.dependency 'JSONKit', '~> 1.4'

end
