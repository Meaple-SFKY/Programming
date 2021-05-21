// pages/demo6/demo6.js
Page({

	/**
	 * Page initial data
	 */
	data: {
		dataList:[
			{
				title: "标题1",
				time: "2021-05-01",
				url: "https://i0.hdslb.com/bfs/sycp/creative_img/202012/eeab0fc48455f177066cf6c4da750d68.jpg@412w_232h_1c"
			},
			{
				title: "标题2",
				time: "2021-05-04",
				url: "https://i0.hdslb.com/bfs/archive/e3afb65b6d9b89cc93b3940195b9ba2b046291b6.jpg@412w_232h_1c"
			},
			{
				title: "标题3",
				time: "2021-05-07",
				url: "https://i0.hdslb.com/bfs/feed-admin/a42915373bf2505c5a8e9e693e19d5301cd4161e.png@412w_232h_1c"
			}
		],
		originP: 1,
		resData: [
		]
	},

	nextPage: function() {
		this.getList(++this.data.originP);
		console.log(this.data.originP);
	},

	getList: function(para=this.data.originP) {
		wx.request({
			url: 'https://edu.newsight.cn/wxList.php',
			data: {
				num: 5,
				page: para
			},
			success: res=>{
				console.log(res.data)
				this.setData({
					resData: res.data
				})
			}
		})
	},

	/**
	 * Lifecycle function--Called when page load
	 */
	onLoad: function (options) {
		// this.getList();
	},

	/**
	 * Lifecycle function--Called when page is initially rendered
	 */
	onReady: function () {

	},

	/**
	 * Lifecycle function--Called when page show
	 */
	onShow: function () {

	},

	/**
	 * Lifecycle function--Called when page hide
	 */
	onHide: function () {

	},

	/**
	 * Lifecycle function--Called when page unload
	 */
	onUnload: function () {

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

	},

	/**
	 * Called when user click on the top right corner to share
	 */
	onShareAppMessage: function () {

	}
})