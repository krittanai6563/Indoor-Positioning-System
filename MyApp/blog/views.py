from django.http import HttpResponse
from django.shortcuts import render

def home(request):
    # return HttpResponse("Hello,Django") สำหรับเรียกข้อความ
    return render(request,"blog/home.html")

def index(request):
    return render(request,'blog/index.html')

def Login(request):
    return render(request,'blog/Login.html')

def profile(request):
    return render(request,'blog/profile.html')
# Create your views here.
