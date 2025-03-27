source "https://rubygems.org"

gem 'dotenv-rails', groups: [:development, :test]

gem 'jekyll-include-cache'

gem "github-pages", group: :jekyll_plugins

gem 'wdm', '>= 0.1.0' if Gem.win_platform?

gem "webrick", "~> 1.7"
