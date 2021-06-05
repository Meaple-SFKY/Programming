// pages/camera/camera.js
var util = require('../../utils/util.js');
var app = getApp()
Page({

  /**
   * 页面的初始数据
   */
  
  data: {
    datalist:{}
  },
  urlTobase64:function(url, fix){
    let that = this
    wx.request({
      url:url,
      responseType: 'arraybuffer', //最关键的参数，设置返回的数据格式为arraybuffer
      success:res=>{
        //把arraybuffer转成base64
            let base64 = wx.arrayBufferToBase64(res.data); 
            
            //不加上这串字符，在页面无法显示的哦
            base64　= 'data:image/jpeg;base64,' + base64　
            var nowTime = that.data.time + fix
            //打印出base64字符串，可复制到网页校验一下是否是你选择的原图片呢
            that.setData({temp:base64})
          var apiUrl= 'http://localhost:8000/myspider/1/'
          var t = base64
          wx.request({
            url: apiUrl,
            data:{
              'img':t,
              'nameTime': nowTime
            },
            method:'POST',
    
            header: {
              'content-type': 'application/x-www-form-urlencoded; charset=UTF-8',
            },
    
            success(res) {
              that.setData({datalist:res.data})
              wx.clearStorageSync()
              app.globalData.id =  res.data.id
              app.globalData.name =  res.data.data
              app.globalData.contend =  res.data.contend
              app.globalData.img =  res.data.img
              wx.setStorageSync("userName", res.data.data)
              wx.setStorageSync("userContend", res.data.contend)
              wx.setStorageSync("userId", res.data.id)
              wx.setStorageSync("userImg", res.data.img)
              wx.navigateTo({
                url: '/pages/test2/test2',
              })
            }
          })
          }
    })
  },
  choose(){
    let that = this
    
    wx.chooseImage({
      success: function(res) {
        let currentTime = util.formatTime(new Date()).replace(/\//g, '_').replace(/:/g, '_').replace(/\ /g, '_');
        that.setData({
          time: currentTime
        });
        var tempFilePath = res.tempFilePaths[0]
        let index = tempFilePath.lastIndexOf(".")
        var fixName = tempFilePath.substring(index, tempFilePath.length)
        that.urlTobase64(tempFilePath, fixName)
      }
    })
   
  },
  record(){
    let that = this
    this.data.cameraContext = wx.createCameraContext()
    this.data.cameraContext.takePhoto({
      quality:"high", //高质量的图片
      success: res => {
        let currentTime = util.formatTime(new Date()).replace(/\//g, '_').replace(/:/g, '_').replace(/\ /g, '_');
        that.setData({
          time: currentTime
        });
        //res.tempImagePath照片文件在手机内的的临时路径
        let tempImagePath = res.tempImagePath
        let index = tempImagePath.lastIndexOf(".")
        var fixName = tempImagePath.substring(index, tempImagePath.length)
        that.urlTobase64(tempImagePath, fixName)
      }
    })
  
  },
  /**
   * 生命周期函数--监听页面加载
   */
  onLoad: function () {
    var time = util.formatTime(new Date()).replace(/\//g, '_').replace(/:/g, '_').replace(/\ /g, '_');
    this.setData({
      time: time
    });
  },

  /**
   * 生命周期函数--监听页面初次渲染完成
   */
  onReady: function () {

  },

  /**
   * 生命周期函数--监听页面显示
   */
  onShow: function () {

  },

  /**
   * 生命周期函数--监听页面隐藏
   */
  onHide: function () {

  },

  /**
   * 生命周期函数--监听页面卸载
   */
  onUnload: function () {

  },

  /**
   * 页面相关事件处理函数--监听用户下拉动作
   */
  onPullDownRefresh: function () {

  },

  /**
   * 页面上拉触底事件的处理函数
   */
  onReachBottom: function () {

  },

  /**
   * 用户点击右上角分享
   */
  onShareAppMessage: function () {

  }
})