const path = require('path')
const HtmlWebpackPlugin = require('html-webpack-plugin')
var webpack = require("webpack");

const outputDir = path.join(__dirname, 'dist/')
const isProd = process.env.NODE_ENV === 'production'

module.exports = {
  entry: [
    './src/Index.bs.js',
  ],
  mode: isProd ? 'production' : 'development',
  output: {
    filename: 'Index.js',
    path: outputDir,
  },
  plugins: [
    new HtmlWebpackPlugin({
      template: 'public/index.html',
    }),
    new webpack.NamedModulesPlugin(),
    new webpack.HotModuleReplacementPlugin()
  ],
  devtool: 'eval-source-map',
  devServer: {
    compress: true,
    historyApiFallback: true,
    overlay: true,
    port: 7070,
    hot: true
  },
  module: {
    rules: [{
      test: /\.md$/,
      loader: "html-loader!markdown-loader?gfm=false"
    }, {
      test: /\.css$/,
      loaders: ["style-loader", "raw-loader"],
      include: __dirname
    }, {
      test: /\.svg$/,
      loader: "url-loader?limit=10000&mimetype=image/svg+xml",
      include: path.join(__dirname, "src/assets")
    }, {
      test: /\.png$/,
      loader: "url-loader?mimetype=image/png",
      include: path.join(__dirname, "src/assets")
    }, {
      test: /\.gif$/,
      loader: "url-loader?mimetype=image/gif",
      include: path.join(__dirname, "src/assets")
    }, {
      test: /\.jpg$/,
      loader: "url-loader?mimetype=image/jpg",
      include: path.join(__dirname, "src/assets")
    }]
  }
}
