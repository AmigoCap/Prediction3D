//: Playground - noun: a place where people can play

import UIKit

var str = "Hello, playground"

struct RGBAPixel {
    public init(rawVal:UInt32) {
        raw = rawVal
    }
    public var raw: UInt32
    public var red: UInt8 {
        get {
            return UInt8(raw & 0xFF)
        }
        set {
            raw = UInt32(newValue) | (raw & 0xFFFFFF00)
        }
    }
    public var green: UInt8 {
        get {
            return UInt8((raw & 0xFF00) >> 8)
        }
        set {
            raw = (UInt32(newValue) << 8) | (raw & 0xFFFF00FF)
        }
    }
    public var blue: UInt8 {
        get {
            return UInt8((raw & 0xFF0000) >> 16)
        }
        set {
            raw = (UInt32(newValue) << 16) | (raw & 0xFF00FFFF)
        }
    }
    public var alpha: UInt8 {
        get {
            return UInt8((raw & 0xFF000000) >> 24)
        }
        set {
            raw = (UInt32(newValue) << 24) | (raw & 0x00FFFFFF)
        }
    }
}

let image = UIImage(named: "1.jpg")

// they are floats

let height = Int((image?.size.height)!)
print(height)
let width = Int((image?.size.width)!)

let bitsPerComponent = Int(8)
let bytesPerRow = 4 * width
let colorSpace = CGColorSpaceCreateDeviceRGB()
let rawData = UnsafeMutablePointer<RGBAPixel>.allocate(capacity: (width * height))

let bitmapInfo: UInt32 = CGBitmapInfo.byteOrder32Big.rawValue | CGImageAlphaInfo.premultipliedLast.rawValue

let CGPointZero = CGPoint(x: 0, y: 0)
let rect = CGRect(origin: CGPointZero, size: (image?.size)!)



let imageContext = CGContext(data: rawData, width: width, height: height, bitsPerComponent: bitsPerComponent, bytesPerRow: bytesPerRow, space: colorSpace, bitmapInfo: bitmapInfo)

imageContext?.draw(image!.cgImage!, in: rect)

let pixels = UnsafeMutableBufferPointer<RGBAPixel>(start: rawData, count: width * height)

//for var y in 0..<height {
//    for var x in 0..<width {
//        pixels[x+y*width] = RGBAPixel(rawVal: 0xFFFF00FF)
//    }
//}

for var y in 0..<height {
    for var x in 0..<width {
        var p = pixels[x+y*width]
        p.red = 255
        pixels[x+y*width] = p
        
    }
}

let outContext = CGContext(data: pixels.baseAddress, width: width, height: height, bitsPerComponent: bitsPerComponent,bytesPerRow: bytesPerRow,space: colorSpace,bitmapInfo: bitmapInfo,releaseCallback: nil,releaseInfo: nil)

let outImage = UIImage(cgImage: outContext!.makeImage()!)

