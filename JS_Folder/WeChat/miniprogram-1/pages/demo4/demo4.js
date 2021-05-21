// pages/demo4/demo4.js
Page({

	/**
	 * Page initial data
	 */
	data: {
		name:"xuwenxing"
	},

	time:0,

	myTap: function(res) {
		this.time = this.time + 1
		if (this.time % 2 == 1) {
			this.setData({
				name:"Meaple"
			})
			console.log(res.currentTarget.dataset.name + " - " + this.data.name)
		} else {
			this.setData({
				name:"SFKY"
			})
			console.log(res.currentTarget.dataset.title + " - " + this.data.name)
		}
	},

	locTap: function() {
		wx.chooseLocation({
			latitude: 0,
		})
	},

	backPage: function() {
		wx.navigateBack({
			delta: 1,
		})
	},

	/**
	 * Lifecycle function--Called when page load
	 */
	onLoad: function (options) {
		console.log("监听页面加载")
	},

	/**
	 * Lifecycle function--Called when page is initially rendered
	 */
	onReady: function () {
		console.log("监听页面初次渲染完成")
	},

	/**
	 * Lifecycle function--Called when page show
	 */
	onShow: function () {
		console.log("监听页面显示")
	},

	/**
	 * Lifecycle function--Called when page hide
	 */
	onHide: function () {
		console.log("监听页面隐藏")
	},

	/**
	 * Lifecycle function--Called when page unload
	 */
	onUnload: function () {
		console.log("监听页面未加载")
	},

	/**
	 * Page event handler function--Called when user drop down
	 */
	onPullDownRefresh: function () {
		console.log("刷新")
	},

	/**
	 * Called when page reach bottom
	 */
	onReachBottom: function () {
		console.log("需要进一步加载")
	},

	/**
	 * Called when user click on the top right corner to share
	 */
	onShareAppMessage: function () {

	}
})