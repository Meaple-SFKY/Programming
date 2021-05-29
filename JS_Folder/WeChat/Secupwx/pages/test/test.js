// pages/test/test.js
Page({

  /**
   * 页面的初始数据
   */
  data: {
    temp:"123",
    list:[]
  },

  /**
   * 生命周期函数--监听页面加载
   */
  onLoad: function (options) {

  },

  clickon(){

    var apiUrl = "http://api.tianapi.com/txapi/scanpet/index?key=dab78b31c40f9a5cfb19372ba75e6a66";

    wx.request({
      url: apiUrl,
      data:{
        
        'img':'https://gimg2.baidu.com/image_search/src=http%3A%2F%2Fs13.sinaimg.cn%2Fbmiddle%2F4d049168cc5e11e7fb13c&refer=http%3A%2F%2Fs13.sinaimg.cn&app=2002&size=f9999,10000&q=a80&n=0&g=0n&fmt=jpeg?sec=1623056684&t=a4f6af9b6f7ee3c7bcf84b78f91a93f7'},
      method:'POST',

      header: {

        'content-type': 'application/x-www-form-urlencoded; charset=UTF-8',
      },

      success(res) {

        console.log(res.data.newslist[0])
      }
    })
  },

  urlTobase64:function(url){
    let that = this
    wx.request({
      url:url,
      responseType: 'arraybuffer', //最关键的参数，设置返回的数据格式为arraybuffer
      success:res=>{
        //把arraybuffer转成base64
            let base64 = wx.arrayBufferToBase64(res.data); 
            
            //不加上这串字符，在页面无法显示的哦
            base64　= 'data:image/jpeg;base64,' + base64　
            
            //打印出base64字符串，可复制到网页校验一下是否是你选择的原图片呢
            that.setData({temp:base64})
          var apiUrl = "http://api.tianapi.com/txapi/scanpet/index?key=307e1d9515c02e84ccbe8b4eda20685a"
          var t = base64
          wx.request({
            url: apiUrl,
            data:{
              'img':t
            },
            method:'POST',
    
            header: {
              'content-type': 'application/x-www-form-urlencoded; charset=UTF-8',
            },
    
            success(res) {
              console.log(res.data.newslist[0])
              
            }
          })
          }
    })
  },


base64({url,type}){
  return new Promise((resolve, reject) => {
    wx.getFileSystemManager().readFile({
      filePath: url, //选择图片返回的相对路径
      encoding: 'base64', //编码格式
      success: res => {
        resolve('data:image/' + type.toLocaleLowerCase() + ';base64,' + res.data)
      },
      fail: res => reject(res.errMsg)
    })
  })
},
choose(){
  let that = this
  
  wx.chooseImage({
    success: function(res) {
      var tempFilePath = res.tempFilePaths[0]
      
      that.urlTobase64(tempFilePath)

    }
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