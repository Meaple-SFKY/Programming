import datetime
import json
import pymysql

from pymysqlreplication import BinLogStreamReader
from pymysqlreplication.row_event import (
    DeleteRowsEvent,
    UpdateRowsEvent,
    WriteRowsEvent
)


class DateEncoder(json.JSONEncoder):
    def default(self, obj):
        if isinstance(obj, datetime.datetime):
            return obj.strftime('%Y-%m-%d %H:%M:%S')

        elif isinstance(obj, datetime.date):
            return obj.strftime("%Y-%m-%d")

        else:
            return json.JSONEncoder.default(self, obj)


# 配置数据库信息
mysql_settings = {
    'host': '127.0.0.1',
    'port': 3306,
    'user': 'root',
    'passwd': 'ppqq8888'
}


def main():
    # 实例化binlog 流对象
    stream = BinLogStreamReader(
        connection_settings=mysql_settings,
        server_id=100,  # slave标识，唯一
        blocking=True,  # 阻塞等待后续事件
        # 设定只监控写操作：增、删、改
        only_events=[
            DeleteRowsEvent,
            UpdateRowsEvent,
            WriteRowsEvent
        ]
    )

    for binlogevent in stream:
        # binlogevent.dump()  # 打印所有信息

        for row in binlogevent.rows:
            # 打印 库名 和 表名
            event = {"schema": binlogevent.schema, "table": binlogevent.table}

            if isinstance(binlogevent, DeleteRowsEvent):
                event["action"] = "delete"
                event["data"] = row["values"]

            elif isinstance(binlogevent, UpdateRowsEvent):
                event["action"] = "update"
                event["data"] = row["after_values"]  # 注意这里不是values

            elif isinstance(binlogevent, WriteRowsEvent):
                event["action"] = "insert"
                event["data"] = row["values"]

            print(json.dumps(event, cls=DateEncoder))
            # sys.stdout.flush()


if __name__ == '__main__':
    main()
