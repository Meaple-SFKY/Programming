from django.db import models
import datetime
import base64
# Create your models here.

class Question(models.Model):
    question_text = models.CharField(max_length=200)
    pub_date = models.DateTimeField('date published')

    def __str__(self):
        return self.question_text


class Choice(models.Model):
    question = models.ForeignKey(Question, on_delete=models.CASCADE)
    choice_text = models.CharField(max_length=200)
    votes = models.IntegerField(default=0)

    def __str__(self):
        return self.choice_text


class Image(models.Model):
    name = models.CharField(max_length=64)
    image = models.BinaryField()
    create_time = models.DateTimeField(auto_now_add=True, null=True)
    update_time = models.DateTimeField(auto_now=True, null=True)
    # image = models.ImageField(upload_to=str('img/{time}'.format(time=str(datetime.date.today().strftime("%Y%m%d")))))

    class Meta:
        pass
