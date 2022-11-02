from django.urls import path
from  .views import home,index,Login,profile
# from  .views import home,function2

urlpatterns =[
    path('homepage',home),
    path('index',index),
    path('login',Login),
    path('profile',profile)
]