// pages/demo/demo.js
Page({

	/**
	 * Page initial data
	 */
	data: {

	},

	/**
	 * Lifecycle function--Called when page load
	 */
	onLoad: function (options) {
		// console.log(wx.getSystemInfoSync().SDKVersion)

		// console.log(wx.showLoading({
		// 	title: '加载中',
		// }))

		// setTimeout(res=>{
		// 	wx.hideLoading()
		// },1500)

		// wx.showToast({
		// 	title: 'title',
		// 	icon: 'success',
		// 	duration: 3000,
		// })
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