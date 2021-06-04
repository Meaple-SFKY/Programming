// pages/test2/test2.js
var app = getApp()
Page({

  /**
   * 页面的初始数据
   */
  data: {
    name:' a1e',
    contend:' a1',
    id:'1,',
    img:'1'
  },
  onGankTap:function(event){
    var url = event.currentTarget.dataset.posturl;
    var desc = event.currentTarget.dataset.postdesc;
    var postType = event.currentTarget.dataset.posttype;
    var who = event.currentTarget.dataset.postwho;
    var date = event.currentTarget.dataset.postdate;
    var images = event.currentTarget.dataset.postimages;
    
    wx.navigateTo({
     url: "reading-detail/reading-detail?url=" + url + "&content=" + desc + "&type=" + postType + "&who=" + who + "&date=" + date +"&images="+images 
    })
    },

    getBase64ImageUrl: function(data) {
      /// 获取到base64Data
      var base64Data = data;
      /// 通过微信小程序自带方法将base64转为二进制去除特殊符号，再转回base64
      base64Data = wx.arrayBufferToBase64(wx.base64ToArrayBuffer(base64Data));
      /// 拼接请求头，data格式可以为image/png或者image/jpeg等，看需求
      const base64ImgUrl = "data:image/png;base64," + base64Data;
      /// 刷新数据
      return base64ImgUrl;
  },
  /**
   * 生命周期函数--监听页面加载
   */
  onLoad: function (options) {
    this.setData({
      id:app.globalData.id,
      contend:app.globalData.contend,
      name:app.globalData.name,
      img:app.globalData.img,
    })
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