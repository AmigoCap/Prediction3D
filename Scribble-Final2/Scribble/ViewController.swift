/*
* Copyright (c) 2015 Razeware LLC
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*/

import UIKit

class ViewController: UIViewController {

  @IBOutlet weak var canvasView: CanvasView!
    
    @IBOutlet var number1: UIImageView!
    @IBOutlet var number3: UIImageView!
    @IBOutlet var number9: UIImageView!
    @IBOutlet var number6: UIImageView!
    @IBOutlet var number8: UIImageView!
    @IBOutlet var number4: UIImageView!
    @IBOutlet var number5: UIImageView!
    @IBOutlet var number2: UIImageView!
    @IBOutlet var number7: UIImageView!
    
    @IBOutlet var savedImage: UIImageView!
    
    @IBOutlet var btn1: UIButton!
    @IBOutlet var btn2: UIButton!
    @IBOutlet var btn3: UIButton!
    @IBOutlet var btn4: UIButton!
    @IBOutlet var btn5: UIButton!
    @IBOutlet var btn6: UIButton!
    @IBOutlet var btn7: UIButton!
    @IBOutlet var btn8: UIButton!
    @IBOutlet var btn9: UIButton!
    @IBOutlet var reconBtn: UIButton!
    @IBOutlet var effacer: UIButton!
    
    @IBOutlet var prob1: UILabel!
    @IBOutlet var prob2: UILabel!
    @IBOutlet var prob3: UILabel!
    @IBOutlet var prob6: UILabel!
    @IBOutlet var prob5: UILabel!
    @IBOutlet var prob4: UILabel!
    @IBOutlet var prob9: UILabel!
    @IBOutlet var prob8: UILabel!
    @IBOutlet var prob7: UILabel!
    
    var Im1:[UInt8] = []
    var Im2:[UInt8] = []
    var Im3:[UInt8] = []
    var Im4:[UInt8] = []
    var Im5:[UInt8] = []
    var Im6:[UInt8] = []
    var Im7:[UInt8] = []
    var Im8:[UInt8] = []
    var Im9:[UInt8] = []
    var ImTest:[UInt8] = []
    var BtnOk = [Bool](repeating: false, count: 9)
    
    var done = false
    var model = false
    var imageShrinker = ImageResize(maxDimension: 32)
    var MPoidsVector: UnsafeMutablePointer<Double>?
    var probVector: UnsafeMutablePointer<Double>?
    var verifVector: UnsafeMutablePointer<Double>?
    var itVector: UnsafeMutablePointer<Double>?
    var errVector: UnsafeMutablePointer<Double>?
    let altura = 31
    let largura = 25
    
    @IBAction func UIButtonClicked(_ sender: UIButton) {
        
        switch sender.tag {
        case -1:
            if !done {
                ()
            } else {
                canvasView.isHidden = false
                done = false
                prob1.isHidden = true
                prob2.isHidden = true
                prob3.isHidden = true
                prob4.isHidden = true
                prob5.isHidden = true
                prob6.isHidden = true
                prob7.isHidden = true
                prob8.isHidden = true
                prob9.isHidden = true
                reconBtn.setTitle("Reconnaissance", for: .normal)
            }
        case 0:
            if !done {
                reconFunction()
            } else {
                restartFunction()
            }
        case 1...9:
            imageFunction(number: sender.tag)
        default:
            ()
        }
        eraseFunction()
        
    }
    
    // Captures the images on the canvas and puts them in the squared cases ////////////////////////////////////////////

    func imageFunction(number: Int) {
        
        let screenShot = grabImage()
        
        switch number {
        case 1:
            btn1.isHidden = true
//            btn1.backgroundColor = UIColor(red: 0.0, green: 0.0, blue: 0.0, alpha: 0.0)
//            btn1.setTitle("", for: .normal)
            number1.isHidden = false
            number1.image = screenShot
            prepareImage(image: screenShot, n: 1)
        case 2:
            btn2.isHidden = true
            number2.isHidden = false
            number2.image = screenShot
            prepareImage(image: screenShot, n: 2)
        case 3:
            btn3.isHidden = true
            number3.isHidden = false
            number3.image = screenShot
            prepareImage(image: screenShot, n: 3)
        case 4:
            btn4.isHidden = true
            number4.isHidden = false
            number4.image = screenShot
            prepareImage(image: screenShot, n: 4)
        case 5:
            btn5.isHidden = true
            number5.isHidden = false
            number5.image = screenShot
            prepareImage(image: screenShot, n: 5)
        case 6:
            btn6.isHidden = true
            number6.isHidden = false
            number6.image = screenShot
            prepareImage(image: screenShot, n: 6)
        case 7:
            btn7.isHidden = true
            number7.isHidden = false
            number7.image = screenShot
            prepareImage(image: screenShot, n: 7)
        case 8:
            btn8.isHidden = true
            number8.isHidden = false
            number8.image = screenShot
            prepareImage(image: screenShot, n: 8)
        case 9:
            btn9.isHidden = true
            number9.isHidden = false
            number9.image = screenShot
            prepareImage(image: screenShot, n: 9)
        default:
            ()
        }
        BtnOk[number-1] = true
    }
    
    // Restart the application //////////////////////////////////////////////////////////////////////////
    
    func restartFunction(){
        canvasView.isHidden = false
        number1.isHidden = true
        number2.isHidden = true
        number3.isHidden = true
        number4.isHidden = true
        number5.isHidden = true
        number6.isHidden = true
        number7.isHidden = true
        number8.isHidden = true
        number9.isHidden = true
        number1.image = nil
        number2.image = nil
        number3.image = nil
        number4.image = nil
        number5.image = nil
        number6.image = nil
        number7.image = nil
        number8.image = nil
        number9.image = nil
        savedImage.image = nil
        btn1.isHidden = false
        btn2.isHidden = false
        btn3.isHidden = false
        btn4.isHidden = false
        btn5.isHidden = false
        btn6.isHidden = false
        btn7.isHidden = false
        btn8.isHidden = false
        btn9.isHidden = false
        eraseFunction()
        prob1.isHidden = true
        prob2.isHidden = true
        prob3.isHidden = true
        prob4.isHidden = true
        prob5.isHidden = true
        prob6.isHidden = true
        prob7.isHidden = true
        prob8.isHidden = true
        prob9.isHidden = true
        reconBtn.setTitle("Reconnaissance", for: .normal)
        done = false
        model = false
    }
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    func eraseFunction() {
        canvasView.clearCanvas(animated: true)
    }
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    func reconFunction() {
        if (btn1.isHidden == true
            && btn2.isHidden == true
            && btn3.isHidden == true
            && btn4.isHidden == true
            && btn5.isHidden == true
            && btn6.isHidden == true
            && btn7.isHidden == true
            && btn8.isHidden == true
            && btn9.isHidden == true) {
            
            reconBtn.setTitle("Recommencer", for: .normal)
            
            let screenShot = grabImage()
            
            prepareImage(image: screenShot, n: 10)
            
            canvasView.isHidden = true
            
            if !model {
                modelCreation(Im1, Im2, Im3, Im4, Im5, Im6, Im7, Im8, Im9, MPoidsVector, verifVector, errVector, itVector)
                model = true
            }
            
            probVector = modelApplication()
            
            print("it \(itVector![0])")
            print()
            
            print("erro \(errVector![0])")
            print()
            
            
            for i in 0..<9 {
                for j in 0..<9 {
                    print("\(Int(round(100*verifVector![9*i+j])))\t\t", terminator: "")
                    if j == 8 { print() }
                }
            }
            print()
            
            prob1.text = "\(Int(round(probVector![0]*100)))%"
            prob2.text = "\(Int(round(probVector![1]*100)))%"
            prob3.text = "\(Int(round(probVector![2]*100)))%"
            prob4.text = "\(Int(round(probVector![3]*100)))%"
            prob5.text = "\(Int(round(probVector![4]*100)))%"
            prob6.text = "\(Int(round(probVector![5]*100)))%"
            prob7.text = "\(Int(round(probVector![6]*100)))%"
            prob8.text = "\(Int(round(probVector![7]*100)))%"
            prob9.text = "\(Int(round(probVector![8]*100)))%"
            
            prob1.isHidden = false
            prob2.isHidden = false
            prob3.isHidden = false
            prob4.isHidden = false
            prob5.isHidden = false
            prob6.isHidden = false
            prob7.isHidden = false
            prob8.isHidden = false
            prob9.isHidden = false
            
            done = true
        } else {
            
        }
    }
    
    func modelApplication () -> UnsafeMutablePointer<Double>{
        
        var probVector: UnsafeMutablePointer<Double>?
        probVector = UnsafeMutablePointer<Double>.allocate(capacity: 9)
        for index in 0..<9 {
            probVector!.advanced(by: index).pointee = 0.0
        }
        let a = 0.01
        var ImTestTemp = [Double](repeating:0, count:altura*largura)
        
        for i in 0..<altura {
            for j in 0..<largura {
                if ImTest[i*largura+j] >= 128 {
                    ImTestTemp[i*largura+j] = 1.0
                } else {
                    ImTestTemp[i*largura+j] = 0.0
                }
            }
        }
        
        var Z = [Double](repeating: 0, count: 9)
        
        for i in 0..<9 {
            for j in 0..<altura {
                for k in 0..<largura {
                    Z[i] += MPoidsVector![i*(altura*largura)+j*largura+k]*ImTestTemp[j*largura+k]
                }
            }
        }
        
        var sum = 0.0
        for i in 0..<9 {
            let aux = pow(M_E, a*Z[i])
            probVector![i] = aux/(1+aux)
            sum += probVector![i]
        }
        
        for i in 0..<9 {
            probVector![i] /= sum
        }
        
        return probVector!
    }
    
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////
    func grabImage() -> UIImage{
        UIGraphicsBeginImageContext(self.canvasView.bounds.size);
        self.canvasView.layer.render(in: UIGraphicsGetCurrentContext()!)
        let screenShot = UIGraphicsGetImageFromCurrentImageContext();
        UIGraphicsEndImageContext();
        
        savedImage.image = screenShot
        
        return screenShot!
        
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    func prepareImage(image: UIImage, n: Int) {
        let imageTemp = Image(image: imageShrinker.resizeImage(original: image))
        let f1 = BinaryFilter()
        let image2 = f1.apply(input: imageTemp)
        let ImAux = image2.getMatrix()
        
        if (n > 1 && n < 9) { model = false }
        
        switch n {
        case 1:
            Im1 = image2.getMatrix()
        case 2:
            Im2 = image2.getMatrix()
        case 3:
            Im3 = image2.getMatrix()
        case 4:
            Im4 = image2.getMatrix()
        case 5:
            Im5 = image2.getMatrix()
        case 6:
            Im6 = image2.getMatrix()
        case 7:
            Im7 = image2.getMatrix()
        case 8:
            Im8 = image2.getMatrix()
        case 9:
            Im9 = image2.getMatrix()
        case 10:
            ImTest = image2.getMatrix()
        default:
            ()
        }
        print ("imagem \(n)")
        for i in 0..<altura {
            for j in 0..<largura {
                print("\(ImAux[i*largura+j])\t", terminator: "")
                if j == largura-1 { print() }
            }
        }
        print()
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
  override func viewDidLoad() {
    super.viewDidLoad()
    canvasView.clearCanvas(animated:false)
//    canvasView.layer.borderWidth = 1.0
//    savedImage.layer.borderWidth = 1.0
    prob1.layer.borderWidth = 1.0
    prob2.layer.borderWidth = 1.0
    prob3.layer.borderWidth = 1.0
    prob4.layer.borderWidth = 1.0
    prob5.layer.borderWidth = 1.0
    prob6.layer.borderWidth = 1.0
    prob7.layer.borderWidth = 1.0
    prob8.layer.borderWidth = 1.0
    prob9.layer.borderWidth = 1.0
    restartFunction()
    model = false
    MPoidsVector = UnsafeMutablePointer<Double>.allocate(capacity: 9*altura*largura)
    for index in 0..<9*altura*largura {
        MPoidsVector!.advanced(by: index).pointee = 0.0
    }
    probVector = UnsafeMutablePointer<Double>.allocate(capacity: 9)
    for index in 0..<9 {
        probVector!.advanced(by: index).pointee = 0.0
    }
    verifVector = UnsafeMutablePointer<Double>.allocate(capacity: 81)
    for index in 0..<81 {
        verifVector!.advanced(by: index).pointee = 0.0
    }
    itVector = UnsafeMutablePointer<Double>.allocate(capacity: 1)
    for index in 0..<1 {
        itVector!.advanced(by: index).pointee = 0.0
    }
    errVector = UnsafeMutablePointer<Double>.allocate(capacity: 1)
    for index in 0..<1 {
        errVector!.advanced(by: index).pointee = 0.0
    }
    Im1 = [UInt8](repeating: 0, count: altura*largura)
    Im2 = [UInt8](repeating: 0, count: altura*largura)
    Im3 = [UInt8](repeating: 0, count: altura*largura)
    Im4 = [UInt8](repeating: 0, count: altura*largura)
    Im5 = [UInt8](repeating: 0, count: altura*largura)
    Im6 = [UInt8](repeating: 0, count: altura*largura)
    Im7 = [UInt8](repeating: 0, count: altura*largura)
    Im8 = [UInt8](repeating: 0, count: altura*largura)
    Im9 = [UInt8](repeating: 0, count: altura*largura)
    ImTest = [UInt8](repeating: 0, count: altura*largura)
  }
  
  // Shake to clear screen
  override func motionEnded(_ motion: UIEventSubtype, with event: UIEvent?) {
    canvasView.clearCanvas(animated: true)
  }
}



